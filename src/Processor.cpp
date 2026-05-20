#include "Processor.hpp"
#include <chrono>
#include <iostream>
#include <thread>

void Processor::main_loop() {
  // our cpu cycles are a budget we need to work against
  // the gameboy had to depend on a certain amount of cpu cycles to draw the
  // pixels and implement game logic nowadays we have higher level functoins and
  // logic, but back in the day a cpu cycle limit was 70k per frame and those
  // commands were literally increment the b register and that would take up 4
  // cycles some commands such as load would take up 12 cycles it was very
  // restricted, but we dont have that limitation but inorder to emulate the
  // gameboy, we need to emulate that restriction so per frame, which would
  // be 59.7 frames per second, we'd have around 70k we need to process around
  // 70k worth of cpu cycles of commands before a frame is rendered but seeing
  // as our cpu's are behemoths compared to the tiny gameboy cpu, we are going
  // to acheive those cpu cycles in miliseconds especially since we'd be doing
  // simple instructional function calls therefore we need to put our thread to
  // sleep once we've hit our cpu cycle's budget for the frame if we've hit the
  // budget, we're going draw and if we've drawn the frame before our
  // refreshrate has caught up, we need to put our thread to sleep.

  // our running flag
  bool emulator_is_running = true;
  // the max cycles we're allowed per frame is approx 70k
  const int MAX_CYCLES_PER_FRAME = 70224;
  // and we need to convert the 59.7 frames per second to miliseconds to play
  // nicely with our computers
  const double TARGET_FRAME_TIME_MS = 1000.0 / 59.7;

  while (emulator_is_running) {
    // we need to capture the time that we started to process a frame
    auto frame_start_time = std::chrono::high_resolution_clock::now();
    // and this is our variable that's going to keep track of our cycles we've
    // used up processing our frame
    int cycles_this_frame = 0;

    // now we're going to loop again whilst comparing the cycles we've processed
    // against our max limit until we've hit our limit of 70k cpu cycles
    // processed
    std::cout << "about to render our frame" << std::endl;
    while (cycles_this_frame < MAX_CYCLES_PER_FRAME) {

      // so we need a class for rom reading and extracting op code
      // once we've got our op code, we can give it to our function of switch
      // statements of our functions

      // so how is that going to work, so we need to be able to what,
      // read lines or provide op codes for what the rom requires
      // so once we have the op codes that the rom requires, we need to then
      // translate that into our opcode asm translator and once we translate the
      // op to asm, we need to get the appropriate function once we get the
      // functoin, it needs to be called here, in this loop because that
      // function is going to return the cpu cycles

      int cycles_taken = 8; // we need dummy values

      cycles_this_frame += cycles_taken;

      // we need to implement our instruction processor.

      // then we need to update our graphics
      NULL;
      // and then we need to update our audio
      NULL;
    }

    // Once we've ued up our cpu cycles, we can now draw to the screen
    NULL;
    std::cout << "frame rendered" << std::endl;

    // but once we've drawn we need to sleep our main thread so that we can
    // ensure we're not processing outside of what is meant ot be processed if
    // we dont sleep the person playing super mario will experience mario
    // spwanning in, having a goomba flying towards mario like flash and killing
    // mario off before we even have a chance to render in the first ever frame
    // of the game so we need simulate the speed of the gameboy's
    // cpu/motherboard chip idk it was a weird thing.

    // capture the ending time of our rendering flow
    auto frame_end_time = std::chrono::high_resolution_clock::now();
    // compare the time it took to process the frame
    std::chrono::duration<double, std::milli> time_taken =
        frame_end_time - frame_start_time;

    // once we've compared we'd end up with the time left over for us to sit
    // around on

    // compare the time we've got left over and if its still less than what we
    // have alloted for that frame

    if (time_taken.count() < TARGET_FRAME_TIME_MS) {
      // we then sleep our current thread by the left over time we've got
      // alloted for the frame to be rendered.
      std::this_thread::sleep_for(std::chrono::milliseconds(
          static_cast<long long>(TARGET_FRAME_TIME_MS - time_taken.count())));
    }
  }
}
#include <cstdint>
class Processor {
public:
  // the heart and soul of the processor
  // this pc gets incremented and we get to understand where we are in the
  // instructions list the pc is the program counter, it counts how far deep
  // we're into the program itself this is why when you take the cartridge out
  // of the gameboy you have to restart, because the whole loop of the execution
  // depends on the program counter.

  // the program counter increments, then asks the cartridge for the address its
  // on the cartridge then provides the op code. and thats how games run
  uint16_t PC;
  Processor();
  ~Processor();

  void main_loop();
};
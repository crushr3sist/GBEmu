#include <cstdint>

struct Registers {
  union {
    struct {
      uint8_t F; // Flags      : Results of operations using its upper 4 bits
      uint8_t A; // Accumulator: all math and logic operations
    };
    uint16_t AF; // ACCUM + Flags: Used for pushing and poping state to stack
  };
  union {
    struct {
      uint8_t B; //  |
      uint8_t C; //  |
    };
    uint16_t BC; // Index or counter
  };
  union {
    struct {
      uint8_t D; //  | - General Purpose registers
      uint8_t E; //  |    used for memory addressing
    };
    uint16_t DE; // Index or destination for memory reads/writes
  };
  union {
    struct {
      uint8_t H; //  |    or data holding
      uint8_t L; //  |
    };
    uint16_t HL; // memory poitner, read and write specific ram addresses
  };

  // special 16 bit registers
  uint16_t SP; // our stack pointer
  uint16_t PC; // our program counter, most important register, tells us where
               // to look in the cartridge.
};

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
  Processor() = default;
  ~Processor() = default;
  Registers Reg;
  void main_loop();
};
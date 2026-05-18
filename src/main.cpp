#include <iostream>

// okay so we need to firstly emulate our registers.

struct Reg_8_bit {
  uint8_t A; // Accumulator: all math and logic operations
  uint8_t F; // Flags      : Results of operations using its upper 4 bits
  uint8_t B; //  |
  uint8_t C; //  |
  uint8_t D; //  | - General Purpose registers
  uint8_t E; //  |    used for memory addressing
  uint8_t H; //  |    or data holding
  uint8_t L; //  |
};

struct Reg_16_bit {
  uint16_t AF; // ACCUM + Flags: Used for pushing and poping state to stack
  uint16_t BC; // Index or counter
  uint16_t DE; // Index or destination for memory reads/writes
  uint16_t HL; // memory poitner, read and write specific ram addresses

  // special 16 bit registers
  uint16_t SP; //
};

int main() {

  std::cout << "hello world" << std::endl;
  return 0;
}
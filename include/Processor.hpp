#include "MMU.hpp"
#include <cstdint>

struct Flags {
  uint8_t Z;
  uint8_t N;
  uint8_t H;
  uint8_t C;
};
struct Registers {
  union {
    struct {
      Flags F;
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

struct Opcode {
  int bytes;
  int cycles;
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
  MMU MMU;

  void main_loop();

  uint8_t fetch_8_bytes();
  uint8_t fetch_16_bytes();

  // Opcodes: 0x
  Opcode _0x0();
  Opcode _0x1();
  Opcode _0x2();
  Opcode _0x3();
  Opcode _0x4();
  Opcode _0x5();
  Opcode _0x6();
  Opcode _0x7();
  Opcode _0x8();
  Opcode _0x9();
  Opcode _0xA();
  Opcode _0xB();
  Opcode _0xC();
  Opcode _0xD();
  Opcode _0xE();
  Opcode _0xF();

  // Opcodes: 1x
  Opcode _1x0();
  Opcode _1x1();
  Opcode _1x2();
  Opcode _1x3();
  Opcode _1x4();
  Opcode _1x5();
  Opcode _1x6();
  Opcode _1x7();
  Opcode _1x8();
  Opcode _1x9();
  Opcode _1xA();
  Opcode _1xB();
  Opcode _1xC();
  Opcode _1xD();
  Opcode _1xE();
  Opcode _1xF();

  // Opcodes: 2x
  Opcode _2x0();
  Opcode _2x1();
  Opcode _2x2();
  Opcode _2x3();
  Opcode _2x4();
  Opcode _2x5();
  Opcode _2x6();
  Opcode _2x7();
  Opcode _2x8();
  Opcode _2x9();
  Opcode _2xA();
  Opcode _2xB();
  Opcode _2xC();
  Opcode _2xD();
  Opcode _2xE();
  Opcode _2xF();

  // Opcodes: 3x
  Opcode _3x0();
  Opcode _3x1();
  Opcode _3x2();
  Opcode _3x3();
  Opcode _3x4();
  Opcode _3x5();
  Opcode _3x6();
  Opcode _3x7();
  Opcode _3x8();
  Opcode _3x9();
  Opcode _3xA();
  Opcode _3xB();
  Opcode _3xC();
  Opcode _3xD();
  Opcode _3xE();
  Opcode _3xF();

  // Opcodes: 4x
  Opcode _4x0();
  Opcode _4x1();
  Opcode _4x2();
  Opcode _4x3();
  Opcode _4x4();
  Opcode _4x5();
  Opcode _4x6();
  Opcode _4x7();
  Opcode _4x8();
  Opcode _4x9();
  Opcode _4xA();
  Opcode _4xB();
  Opcode _4xC();
  Opcode _4xD();
  Opcode _4xE();
  Opcode _4xF();

  // Opcodes: 5x
  Opcode _5x0();
  Opcode _5x1();
  Opcode _5x2();
  Opcode _5x3();
  Opcode _5x4();
  Opcode _5x5();
  Opcode _5x6();
  Opcode _5x7();
  Opcode _5x8();
  Opcode _5x9();
  Opcode _5xA();
  Opcode _5xB();
  Opcode _5xC();
  Opcode _5xD();
  Opcode _5xE();
  Opcode _5xF();

  // Opcodes: 6x
  Opcode _6x0();
  Opcode _6x1();
  Opcode _6x2();
  Opcode _6x3();
  Opcode _6x4();
  Opcode _6x5();
  Opcode _6x6();
  Opcode _6x7();
  Opcode _6x8();
  Opcode _6x9();
  Opcode _6xA();
  Opcode _6xB();
  Opcode _6xC();
  Opcode _6xD();
  Opcode _6xE();
  Opcode _6xF();

  // Opcodes: 7x
  Opcode _7x0();
  Opcode _7x1();
  Opcode _7x2();
  Opcode _7x3();
  Opcode _7x4();
  Opcode _7x5();
  Opcode _7x6();
  Opcode _7x7();
  Opcode _7x8();
  Opcode _7x9();
  Opcode _7xA();
  Opcode _7xB();
  Opcode _7xC();
  Opcode _7xD();
  Opcode _7xE();
  Opcode _7xF();

  // Opcodes: 8x
  Opcode _8x0();
  Opcode _8x1();
  Opcode _8x2();
  Opcode _8x3();
  Opcode _8x4();
  Opcode _8x5();
  Opcode _8x6();
  Opcode _8x7();
  Opcode _8x8();
  Opcode _8x9();
  Opcode _8xA();
  Opcode _8xB();
  Opcode _8xC();
  Opcode _8xD();
  Opcode _8xE();
  Opcode _8xF();

  // Opcodes: 9x
  Opcode _9x0();
  Opcode _9x1();
  Opcode _9x2();
  Opcode _9x3();
  Opcode _9x4();
  Opcode _9x5();
  Opcode _9x6();
  Opcode _9x7();
  Opcode _9x8();
  Opcode _9x9();
  Opcode _9xA();
  Opcode _9xB();
  Opcode _9xC();
  Opcode _9xD();
  Opcode _9xE();
  Opcode _9xF();

  // Opcodes: Ax
  Opcode _Ax0();
  Opcode _Ax1();
  Opcode _Ax2();
  Opcode _Ax3();
  Opcode _Ax4();
  Opcode _Ax5();
  Opcode _Ax6();
  Opcode _Ax7();
  Opcode _Ax8();
  Opcode _Ax9();
  Opcode _AxA();
  Opcode _AxB();
  Opcode _AxC();
  Opcode _AxD();
  Opcode _AxE();
  Opcode _AxF();

  // Opcodes: Bx
  Opcode _Bx0();
  Opcode _Bx1();
  Opcode _Bx2();
  Opcode _Bx3();
  Opcode _Bx4();
  Opcode _Bx5();
  Opcode _Bx6();
  Opcode _Bx7();
  Opcode _Bx8();
  Opcode _Bx9();
  Opcode _BxA();
  Opcode _BxB();
  Opcode _BxC();
  Opcode _BxD();
  Opcode _BxE();
  Opcode _BxF();

  // Opcodes: Cx
  Opcode _Cx0();
  Opcode _Cx1();
  Opcode _Cx2();
  Opcode _Cx3();
  Opcode _Cx4();
  Opcode _Cx5();
  Opcode _Cx6();
  Opcode _Cx7();
  Opcode _Cx8();
  Opcode _Cx9();
  Opcode _CxA();
  Opcode _CxB();
  Opcode _CxC();
  Opcode _CxD();
  Opcode _CxE();
  Opcode _CxF();

  // Opcodes: Dx
  Opcode _Dx0();
  Opcode _Dx1();
  Opcode _Dx2();
  Opcode _Dx3();
  Opcode _Dx4();
  Opcode _Dx5();
  Opcode _Dx6();
  Opcode _Dx7();
  Opcode _Dx8();
  Opcode _Dx9();
  Opcode _DxA();
  Opcode _DxB();
  Opcode _DxC();
  Opcode _DxD();
  Opcode _DxE();
  Opcode _DxF();

  // Opcodes: Ex
  Opcode _Ex0();
  Opcode _Ex1();
  Opcode _Ex2();
  Opcode _Ex3();
  Opcode _Ex4();
  Opcode _Ex5();
  Opcode _Ex6();
  Opcode _Ex7();
  Opcode _Ex8();
  Opcode _Ex9();
  Opcode _ExA();
  Opcode _ExB();
  Opcode _ExC();
  Opcode _ExD();
  Opcode _ExE();
  Opcode _ExF();

  // Opcodes: Fx
  Opcode _Fx0();
  Opcode _Fx1();
  Opcode _Fx2();
  Opcode _Fx3();
  Opcode _Fx4();
  Opcode _Fx5();
  Opcode _Fx6();
  Opcode _Fx7();
  Opcode _Fx8();
  Opcode _Fx9();
  Opcode _FxA();
  Opcode _FxB();
  Opcode _FxC();
  Opcode _FxD();
  Opcode _FxE();
  Opcode _FxF();
};
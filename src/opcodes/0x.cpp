#include "Processor.hpp"
#include <cstdint>

Opcode Processor::_0x0() { // NOTE - ✓
  /*
    NOP
    1 1
    ----
  */

  Reg.PC++;
  return {1, 1};
}

Opcode Processor::_0x1() { // NOTE - ✓
  /*
    LD BC, d16
    3 3
    ----
  */
  Reg.BC = fetch_16_bytes();
  return {3, 3};
}

Opcode Processor::_0x2() { // NOTE - ✓
  /*
  LD (BC), A
  1 2
  ----
  */
  MMU.write(Reg.BC, Reg.A);

  return {1, 2};
}

Opcode Processor::_0x3() { // NOTE - ✓
  /*
  sinc BC
    1 2
    ----
  */
  Reg.BC++;
  return {1, 2};
}

Opcode Processor::_0x4() { // NOTE - ✓
  /*
  inc B
  1 1
  z0h-
  */

  uint8_t result = Reg.B + 1;

  Reg.F.Z = (result == 0);
  Reg.F.N = 0;
  Reg.F.H = ((Reg.B & 0x0F) + 1) > 0x0F;
  Reg.B = result;

  return {1, 1};
}

Opcode Processor::_0x5() { // NOTE - ✓

  uint8_t result = Reg.B - 1;
  Reg.F.Z = (result == 0);
  Reg.F.N = 1;
  Reg.F.H = ((Reg.B & 0x0F) + 1) > 0x0F;
  Reg.B = result;

  return {1, 1};
}
Opcode Processor::_0x6() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_0x7() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_0x8() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_0x9() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_0xA() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_0xB() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_0xC() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_0xD() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_0xE() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_0xF() {
  int a;
  int b;
  NULL;

  return {1, 1};
}

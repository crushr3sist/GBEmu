#include "Processor.hpp"

Opcode Processor::_0x0() {
  /*
    NOP
    1 1
    ----
  */

  Reg.PC++;
  return {1, 1};
}

Opcode Processor::_0x1() {
  /*
    LD BC, d16
    3 3
    ----
  */
  Reg.BC = fetch_16_bytes();
  return {3, 3};
}

Opcode Processor::_0x2() {
  /*
  LD (BC), A
  1 2
  ----
  */
  MMU.write(Reg.BC, Reg.A);

  return {1, 2};
}

Opcode Processor::_0x3() {
  Reg.BC++;
  return {1, 2};
}

Opcode Processor::_0x4() {
  uint8_t data_from_b = Reg.B;

  data_from_b++;

  Reg.B = data_from_b;

  return {1, 1};
}

Opcode Processor::_0x5() {
  int a;
  int b;
  NULL;

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

#include "Processor.hpp"
#include <cstdint>

Opcode Processor::_2x0() { // NOTE - no clue what jr is
  int a;
  int b;
  NULL;

  return {2, 2};
}

Opcode Processor::_2x1() { // NOTE - ✓
  Reg.HL = fetch_16_bytes();

  return {3, 3};
}
Opcode Processor::_2x2() { // NOTE - ✓
  MMU.write(Reg.HL++, Reg.A);

  return {1, 2};
}
Opcode Processor::_2x3() { // NOTE - ✓
  Reg.HL++;

  return {2, 2};
}
Opcode Processor::_2x4() { // NOTE - ✓
  uint8_t result = Reg.H + 1;
  Reg.F.Z = (result == 0);
  Reg.F.N = 0;
  Reg.F.H = ((Reg.H & 0x0F) + 1) > 0x0F;
  Reg.H = result;

  return {1, 1};
}
Opcode Processor::_2x5() { // NOTE - ✓
  uint8_t result = Reg.H - 1;
  Reg.F.Z = (result == 0);
  Reg.F.N = 1;
  Reg.F.H = ((Reg.H & 0x0F) + 1) > 0x0F;
  Reg.H = result;

  return {1, 1};
}
Opcode Processor::_2x6() {
  int a;
  int b;
  NULL;

  return {2, 2};
}
Opcode Processor::_2x7() {
  int a;
  int b;
  NULL;

  return {2, 2};
}
Opcode Processor::_2x8() {
  int a;
  int b;
  NULL;

  return {2, 2};
}
Opcode Processor::_2x9() {
  int a;
  int b;
  NULL;

  return {2, 2};
}
Opcode Processor::_2xA() {
  int a;
  int b;
  NULL;

  return {2, 2};
}
Opcode Processor::_2xB() {
  int a;
  int b;
  NULL;

  return {2, 2};
}
Opcode Processor::_2xC() {
  int a;
  int b;
  NULL;

  return {2, 2};
}
Opcode Processor::_2xD() {
  int a;
  int b;
  NULL;

  return {2, 2};
}
Opcode Processor::_2xE() {
  int a;
  int b;
  NULL;

  return {2, 2};
}
Opcode Processor::_2xF() {
  int a;
  int b;
  NULL;

  return {2, 2};
}

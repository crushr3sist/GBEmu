#include "Processor.hpp"
#include <cstdint>

Opcode Processor::_1x0() { // NOTE - no clue what stop does
  int a;
  int b;
  NULL;

  return {1, 1};
}

Opcode Processor::_1x1() { // NOTE - ✓
  Reg.DE = fetch_16_bytes();

  return {3, 3};
}

Opcode Processor::_1x2() { // NOTE - ✓
  MMU.write(Reg.DE, Reg.A);

  return {1, 2};
}
Opcode Processor::_1x3() { // NOTE - ✓
  Reg.DE++;

  return {1, 1};
}
Opcode Processor::_1x4() { // NOTE - ✓
  uint8_t result = Reg.D + 1;
  Reg.F.Z = (result == 0);
  Reg.F.N = 0;
  Reg.F.H = ((Reg.D & 0x0F) + 1) > 0x0F;
  Reg.D = result;

  return {1, 1};
}
Opcode Processor::_1x5() { // NOTE - ✓
  uint8_t result = Reg.D - 1;
  Reg.F.Z = (result == 0);
  Reg.F.N = 1;
  Reg.F.H = ((Reg.D & 0x0F) + 1) > 0x0F;
  Reg.D = result;

  return {1, 1};
}
Opcode Processor::_1x6() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_1x7() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_1x8() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_1x9() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_1xA() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_1xB() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_1xC() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_1xD() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_1xE() {
  int a;
  int b;
  NULL;

  return {1, 1};
}
Opcode Processor::_1xF() {
  int a;
  int b;
  NULL;

  return {1, 1};
}

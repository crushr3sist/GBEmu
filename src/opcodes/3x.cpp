#include "Processor.hpp"

Opcode Processor::_3x0() { // NOTE - no clue what jr is
  int a;
  int b;
  NULL;

  return {3, 3};
}

Opcode Processor::_3x1() { // NOTE - ✓
  Reg.SP = fetch_16_bytes();

  return {3, 3};
}
Opcode Processor::_3x2() { // NOTE - ✓

  MMU.write(Reg.HL--, Reg.A);

  return {3, 3};
}
Opcode Processor::_3x3() { // NOTE - ✓
  Reg.SP++;

  return {3, 3};
}
Opcode Processor::_3x4() { // NOTE - ✓
  uint8_t original_val = MMU.read(Reg.HL);
  uint8_t result = original_val + 1;

  Reg.F.Z = (result == 0);
  Reg.F.N = 0;
  Reg.F.H = ((original_val & 0x0F) + 1) > 0x0F;

  MMU.write(Reg.HL, result);

  return {1, 3};
}
Opcode Processor::_3x5() { // NOTE - ✓
  uint8_t original_val = MMU.read(Reg.HL);
  uint8_t result = original_val - 1;

  Reg.F.Z = (result == 0);
  Reg.F.N = 0;
  Reg.F.H = ((original_val & 0x0F) - 1) > 0x0F;

  MMU.write(Reg.HL, result);

  return {1, 3};
}

Opcode Processor::_3x6() {
  int a;
  int b;
  NULL;

  return {3, 3};
}
Opcode Processor::_3x7() {
  int a;
  int b;
  NULL;

  return {3, 3};
}
Opcode Processor::_3x8() {
  int a;
  int b;
  NULL;

  return {3, 3};
}
Opcode Processor::_3x9() {
  int a;
  int b;
  NULL;

  return {3, 3};
}
Opcode Processor::_3xA() {
  int a;
  int b;
  NULL;

  return {3, 3};
}
Opcode Processor::_3xB() {
  int a;
  int b;
  NULL;

  return {3, 3};
}
Opcode Processor::_3xC() {
  int a;
  int b;
  NULL;

  return {3, 3};
}
Opcode Processor::_3xD() {
  int a;
  int b;
  NULL;

  return {3, 3};
}
Opcode Processor::_3xE() {
  int a;
  int b;
  NULL;

  return {3, 3};
}
Opcode Processor::_3xF() {
  int a;
  int b;
  NULL;

  return {3, 3};
}

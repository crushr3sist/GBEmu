#include "Processor.hpp"

Opcode Processor::_4x0() {
  Reg.B = Reg.B;

  return {1, 1};
}

Opcode Processor::_4x1() {
  Reg.B = Reg.C;

  return {1, 1};
}
Opcode Processor::_4x2() {
  Reg.B = Reg.D;

  return {1, 1};
}
Opcode Processor::_4x3() {
  Reg.B = Reg.E;

  return {1, 1};
}
Opcode Processor::_4x4() {
  Reg.B = Reg.H;

  return {1, 1};
}
Opcode Processor::_4x5() {
  Reg.B = Reg.L;

  return {1, 1};
}
Opcode Processor::_4x6() {
  int a;
  int b;
  NULL;

  return {1, 2};
}
Opcode Processor::_4x7() {
  Reg.B = Reg.A;

  return {1, 1};
}
Opcode Processor::_4x8() {
  Reg.C = Reg.B;

  return {1, 1};
}
Opcode Processor::_4x9() {
  Reg.C = Reg.C;

  return {1, 1};
}
Opcode Processor::_4xA() {
  Reg.C = Reg.D;

  return {1, 1};
}
Opcode Processor::_4xB() {
  Reg.C = Reg.E;

  return {1, 1};
}
Opcode Processor::_4xC() {
  Reg.C = Reg.H;

  return {1, 1};
}
Opcode Processor::_4xD() {
  Reg.C = Reg.L;

  return {1, 1};
}
Opcode Processor::_4xE() {
  int a;
  int b;
  NULL;

  return {1, 2};
}
Opcode Processor::_4xF() {
  Reg.C = Reg.A;

  return {1, 1};
}

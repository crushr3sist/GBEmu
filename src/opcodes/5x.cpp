#include "Processor.hpp"

Opcode Processor::_5x0() {
  Reg.D = Reg.B;

  return {1, 1};
}

Opcode Processor::_5x1() {
  Reg.D = Reg.C;

  return {1, 1};
}
Opcode Processor::_5x2() {
  Reg.D = Reg.D;

  return {1, 1};
}
Opcode Processor::_5x3() {
  Reg.D = Reg.E;

  return {1, 1};
}
Opcode Processor::_5x4() {
  Reg.D = Reg.H;

  return {1, 1};
}
Opcode Processor::_5x5() {
  Reg.D = Reg.L;

  return {1, 1};
}
Opcode Processor::_5x6() {
  int a;
  int b;
  NULL;

  return {1, 2};
}
Opcode Processor::_5x7() {
  Reg.D = Reg.A;

  return {1, 1};
}
Opcode Processor::_5x8() {
  Reg.E = Reg.B;

  return {1, 1};
}
Opcode Processor::_5x9() {
  Reg.E = Reg.C;

  return {1, 1};
}
Opcode Processor::_5xA() {
  Reg.E = Reg.D;

  return {1, 1};
}
Opcode Processor::_5xB() {
  Reg.E = Reg.E;

  return {1, 1};
}
Opcode Processor::_5xC() {
  Reg.E = Reg.H;

  return {1, 1};
}
Opcode Processor::_5xD() {
  Reg.E = Reg.L;

  return {1, 1};
}
Opcode Processor::_5xE() {
  int a;
  int b;
  NULL;

  return {1, 2};
}
Opcode Processor::_5xF() {
  Reg.E = Reg.A;

  return {1, 1};
}

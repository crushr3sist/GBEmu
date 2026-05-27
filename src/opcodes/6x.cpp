#include "Processor.hpp"

Opcode Processor::_6x0() {
  Reg.H = Reg.B;

  return {1, 1};
}

Opcode Processor::_6x1() {
  Reg.H = Reg.C;

  return {1, 1};
}
Opcode Processor::_6x2() {
  Reg.H = Reg.D;

  return {1, 1};
}
Opcode Processor::_6x3() {
  Reg.H = Reg.E;

  return {1, 1};
}
Opcode Processor::_6x4() {
  Reg.H = Reg.H;

  return {1, 1};
}
Opcode Processor::_6x5() {
  Reg.H = Reg.L;

  return {1, 1};
}
Opcode Processor::_6x6() {
  int a;
  int b;
  NULL;

  return {1, 2};
}
Opcode Processor::_6x7() {
  Reg.H = Reg.A;

  return {1, 1};
}
Opcode Processor::_6x8() {
  Reg.L = Reg.B;

  return {1, 1};
}
Opcode Processor::_6x9() {
  Reg.L = Reg.C;

  return {1, 1};
}
Opcode Processor::_6xA() {
  Reg.L = Reg.D;

  return {1, 1};
}
Opcode Processor::_6xB() {
  Reg.L = Reg.E;

  return {1, 1};
}
Opcode Processor::_6xC() {
  Reg.L = Reg.H;

  return {1, 1};
}
Opcode Processor::_6xD() {
  Reg.L = Reg.L;

  return {1, 1};
}
Opcode Processor::_6xE() {
  int a;
  int b;
  NULL;

  return {1, 2};
}
Opcode Processor::_6xF() {
  Reg.L = Reg.A;

  return {1, 1};
}

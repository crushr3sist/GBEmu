#include "Processor.hpp"

int main() {

  // so the task at hand is that we need to create a PC which is a program
  // counter. the program counter starts from 0x0100
  Processor main;

  main.main_loop();

  return 0;
}
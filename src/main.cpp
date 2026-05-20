#include <iostream>

#include "Cartridge.hpp"

int main() {

  Cartridge cart;
  std::cout << "reading" << std::endl;
  cart.read_rom("./../test.gb");
  std::cout << "read properly" << std::endl;

  return 0;
}
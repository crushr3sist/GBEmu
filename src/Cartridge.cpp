// so we need a method for reading the whole thing into the cartridge

#include "Cartridge.hpp"
#include <cstdint>
#include <vector>

#include <fstream>
#include <iostream>

#include <vector>

// ensure the correct amount of memory is allocated for our cartridge mmu
Cartridge::Cartridge() { this->cartridge.assign(32768, 0); }
// if the program is destroyed we need to empty the cartridge that's read into
// the mmu
Cartridge::~Cartridge() { this->cartridge.clear(); }

bool Cartridge::read_rom(const char *f) {
  std::ifstream file(f, std::ios::binary | std::ios::ate);

  if (!file.is_open()) {
    std::cerr << "error: couldn't open file" << std::endl;
    return 1;
  }

  std::streamsize file_size = file.tellg();

  file.seekg(0, std::ios::beg);

  if (file.read(reinterpret_cast<char *>(this->cartridge.data()), file_size)) {
    return true;
  }

  return false;
}

uint8_t Cartridge::read_byte(uint16_t address) {
  
  if (address <= 0x7FFF) {
    return this->cartridge[address];
  }

  return 0xFF;
}
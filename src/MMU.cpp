#include "MMU.hpp"

uint8_t MMU::read(uint16_t address) {
  if (address <= 0x7FFF) {
    return cartridge.read_byte(address);
  }

  if (address <= 0x9FFF) {
    return vram[address - 0x8000];
  }

  if (address <= 0xDFFF) {
    return vram[address - 0xC000];
  }

  if (address <= 0xFE9F) {
    return vram[address - 0xFE00];
  }

  if (address <= 0xFF7F) {
    return vram[address - 0xFF00];
  }

  if (address <= 0xFFFE) {
    return vram[address - 0xFF80];
  }

  if (address <= 0xFFFF) {
    return ie;
  }

  return 0xFF;
}

void MMU::write(uint16_t address, uint8_t value) {

  if (address <= 0x7FFF) {
    return;
  }

  if (address <= 0x9FFF) {
    vram[address - 0x8000] = value;
    return;
  }

  if (address <= 0xDFFF) {
    wram[address - 0xC000] = value;
    return;
  }

  if (address <= 0xFE9F) {
    oam[address - 0xFE00] = value;
    return;
  }

  if (address <= 0xFF7F) {
    io[address - 0xFF00] = value;
    return;
  }

  if (address <= 0xFFFE) {
    hram[address - 0xFF80] = value;
    return;
  }

  if (address <= 0xFFFF) {
    ie = value;
  }
}

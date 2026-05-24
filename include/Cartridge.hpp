#pragma once

#include <cstdint>
#include <vector>

class Cartridge {
public:
  Cartridge();
  ~Cartridge();

  bool read_rom(const char *);
  uint8_t read_byte(uint16_t address);

  std::vector<uint8_t> cartridge;

private:
};
#include "Cartridge.hpp"
#include <array>
#include <cstdint>

class MMU {
public:
  Cartridge cartridge;

  std::array<uint8_t, 0x2000> vram; // 0x8000 - 0x9fff
  std::array<uint8_t, 0x2000> wram; // 0xC000 - 0xdfff
  std::array<uint8_t, 0x00A0> oam;  // 0xFE00 - 0xFE9F
  std::array<uint8_t, 0x0080> io;   // 0xFF00 - 0xFF7F
  std::array<uint8_t, 0x007F> hram; // 0xFF80 - 0xFFFE
  uint8_t ie;

  uint8_t read(uint16_t address);
  void write(uint16_t address, uint8_t value);
};

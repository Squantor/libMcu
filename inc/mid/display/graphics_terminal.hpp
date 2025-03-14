/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file graphics_terminal.hpp
 * @brief Graphical terminal middleware
 */
#ifndef GRAPHICS_TERMINAL_HPP
#define GRAPHICS_TERMINAL_HPP

#include <span>
#include <cstdint>
namespace libMcuMid::display {

template <auto &display, auto &font>
struct graphicsTerminal {
  graphicsTerminal() : xpos{0}, ypos{0}, scrollY{0}, scrolling{false} {}
  void write(const char &c) {
    if (c == '\n') {
      ypos += font.height;
      // TODO clear the line
      xpos = 0;
      display.fill(xpos, ypos, display.getXSize(), ypos, 0);
      return;
    }
    if (c == '\r') {
      xpos = 0;
      display.fill(xpos, ypos, display.getXSize(), ypos, 0);
      return;
    }
    auto charBitmap = font.ascii2Bitmap(c);
    display.writeBlock(xpos, ypos, xpos + font.width, ypos, charBitmap);
    xpos += font.width;
    if (xpos >= display.getXSize()) {
      xpos = 0;
      ypos += font.height;
    }
    if (ypos >= display.getYSize()) {
      ypos = 0;
    }
  }
  constexpr void write(std::span<const char> buffer) {
    for (auto c : buffer) {
      write(c);
    }
  }
  /*
  void writeBigChar(auto writeWindow, char c) {
    const uint8_t *bitmap = ascii2Font(consoleFont, c);
    uint8_t bigBitmap[32];
    for (size_t i = 0; i < 16; i++) {
      uint16_t zoomedData = bitZoom(*bitmap);
      bigBitmap[i] = zoomedData;
      bigBitmap[i + 16] = zoomedData >> 8;
      i++;
      bigBitmap[i] = zoomedData;
      bigBitmap[i + 16] = zoomedData >> 8;
      bitmap++;
    }
    writeWindow(xpos, xpos + 15, ypos, ypos + 8, bigBitmap, 32);
    xpos += 16;
    if (xpos >= maxX) {
      xpos = 0;
      ypos += 16;
    }
    if (ypos >= maxY) {
      ypos = 0;
    }
  }
  */
  uint8_t xpos;
  uint8_t ypos;
  uint8_t scrollY;
  bool scrolling;
};
}  // namespace libMcuMid::display

#endif
// The implementation of the Tile.h file
// Implementation file for the set_revealed and display methods of Tile
#include "Tile.h"
#include <iostream>
Tile::Tile() {}

void Tile::set_value(int value) { m_value = value; }

int Tile::get_value() const { return m_value; }

void Tile::set_revealed(bool reveal) { m_revealed = reveal; }

void Tile::display() const {
  if (m_revealed == true) {
    if (m_value == 9) {
      std::cout << "M";
    } else {
      std::cout << m_value;
    }
  } else {
    std::cout << "#";
  }
}
// Your Tile.h File
// header file for the Tile class
#ifndef TILE_H
#define TILE_H
#include <iostream>

class Tile {
private:
  int m_value;
  bool m_revealed = false;

public:
Tile();
void display() const;
void set_revealed(bool reveal);
int get_value() const;
void set_value(int value);
bool is_reveal() const{
    return m_revealed;
}
};

#endif
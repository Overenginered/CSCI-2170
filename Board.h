// The Board.h header file
// header file for the Board class
#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"

class Board {
private:
  int m_board_width;
  int m_board_height;
  int m_size;
  bool has_won = false;
  bool has_lost = false;
  int revealed_count;
  Tile *tiles{};
int minecount;


  void place_mines(int mine_count);
  void update_counts();

public:
  Board(); // Default to 8x8 and 10 mines and run from second constructor
  Board(int rows, int columns, int mine_count); // Custom usernum board
  ~Board(); // When destroying delete the dynamic location
  void print() const;

  void reveal(int row, int col);
  bool gethas_won() const{
      return has_won;
  }
  bool gethas_lost() const{
      return has_lost;
  }
  void display_unrevealed();
};

#endif
// The implementation of the Board.h file
// implementation file for the Board class
#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Default constructor
Board::Board() {
  m_board_width = 8;
  m_board_height = 8;
  m_size = (m_board_width * m_board_height);
  tiles = new Tile[m_size];
  place_mines(10);
  update_counts();
}

// Destructor to destroy/delete the location at the end
Board::~Board() { delete[] tiles; }

// User given dimentions and mine construction
Board::Board(int rows, int columns, int mine_count) {
  m_board_width = rows;
  m_board_height = columns;
  m_size = (m_board_width * m_board_height);
  tiles = new Tile[m_size];
    minecount = mine_count;
  place_mines(mine_count);
  update_counts();

  revealed_count = 0;
}

// Placing the mines both default and user defined
void Board::place_mines(int mine_count) {
  // srand(time(0));
  int random;
  int initial_mines = 0;

  while (initial_mines < mine_count) {
    random = rand() % m_size;
    if (tiles[random].get_value() != 9) {
      tiles[random].set_value(9);
      initial_mines++;
    }
  }
}

// Updating the counter
void Board::update_counts() {
  for (int i = 0; i < m_size; i++) {
    if (tiles[i].get_value() != 9) {
      int counter = 0;
      int i_row = i / m_board_width;
      int i_col = i % m_board_width;
      for (int r = -1; r <= 1; r++) {
        for (int c = -1; c <= 1; c++) {
          int rows = i_row + r;
          int cols = i_col + c;

          if (rows >= 0 && rows < m_board_height && cols >= 0 &&
              cols < m_board_width) {
            int index = m_board_width * rows + cols;
            if (tiles[index].get_value() == 9) {
              counter++;
            }
          }
        }
      }
      tiles[i].set_value(counter);
    }
  }
}
// Printing the board
void Board::print() const {
  std::cout << " ";
  for (int i = 0; i < m_board_width; i++) {
    std::cout << "  " << i << " ";
  }
  std::cout << std::endl;

  std::cout << " |---";
  for (int i = 1; i < m_board_width; i++) {
    std::cout << "|---";
  }
  std::cout << "|" << std::endl;
  for (int i = 0; i < m_board_height; i++) {
    std::cout << i << "| ";
    for (int k = 0; k < m_board_width; k++) {
      if (tiles[i * m_board_width + k].get_value() == 9) {
        std::cout << "M | ";
      } else {
        std::cout << tiles[i * m_board_width + k].get_value() << " | ";
      }
    }
    std::cout << "\n"
              << " |---";
    for (int i = 1; i < m_board_width; i++) {
      std::cout << "|---";
    }
    std::cout << "|" << std::endl;
  }
}

// Revealing the board
void Board::reveal(int row, int col) {
  // checking for coordinate bounds
  if (row < 0 || row >= m_board_height || col < 0 || col >= m_board_width) {
    return;
  }
  // Getting the right index for the tile
  int findindex = row * m_board_width + col;
  Tile &tile = tiles[findindex];

  // if(row, col) revealed
  if (!tile.is_reveal()) {

    // reveal the tile at row,col = set_revealed
    tile.set_revealed(true);

    // if(row, col) is a mine{
    if (tile.get_value() == 9) {
      has_lost = true;
      return;
    }

      revealed_count++;
    // if(row, col) mines have not revealed
    if (revealed_count == ( m_size - minecount) && !has_lost) {
      has_won = true;
      return;
    }
  }
}

  void Board::display_unrevealed(){
    std::cout << " ";
    for (int i = 0; i < m_board_width; i++) {
      std::cout << "  " << i << " ";
    }
    std::cout << std::endl;

    std::cout << " |---";
    for (int i = 1; i < m_board_width; i++) {
      std::cout << "|---";
    }
    std::cout << "|" << std::endl;
    for (int i = 0; i < m_board_height; i++) {
      std::cout << i << "| ";
      for (int k = 0; k < m_board_width; k++) {

        int findindex = i * m_board_width + k;
        if (tiles[findindex].is_reveal()) {
          if (tiles[findindex].get_value() == 9) {
            std::cout << "M | ";
          } else {
            std::cout << tiles[findindex].get_value() << " | ";
          }
        } else {
          std::cout << "# | ";
        }
      }
      std::cout << "\n"
                << " |---";
      for (int i = 1; i < m_board_width; i++) {
        std::cout << "|---";
      }
      std::cout << "|" << std::endl;
    }
  }
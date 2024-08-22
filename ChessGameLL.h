#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <string>

struct Turn {
  std::string move; // algebraic notation string
  char color;       // B for black W for White
  int id;           // which turn is it
};

struct Node {
  Turn data;
  Node *next;
  Node *prev;
};

class ChessGameLL {
private:
  Node *head;
  Node *current_move;

public:
  ChessGameLL();
  ~ChessGameLL();

  bool empty() const;
  void push_back(Turn turn);
  void next_move();
  void prev_move();
  void firstmove();
  void winner();
};

#endif
#include "ChessGameLL.h"
#include <iostream>

ChessGameLL::ChessGameLL() {
  head = nullptr;
  current_move = nullptr;
}
ChessGameLL::~ChessGameLL() {
  Node *curr, *nextone;
  curr = head;
  while (curr) {
    nextone = curr->next;
    delete curr;
    curr = nextone;
  }
  head = current_move = nullptr;
}

bool ChessGameLL::empty() const { return !head; }
void ChessGameLL::push_back(Turn turn) {
  Node *newnode = new Node;
  newnode->data = turn;
  Node *curr = head;
  newnode->prev = nullptr;
  newnode->next = nullptr;
  if (empty()) {
    head = newnode;
    current_move = newnode;
  } else {
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = newnode;
    newnode->prev = curr;
    current_move = newnode;
  }
}
void ChessGameLL::next_move() {
    if(current_move->next == nullptr){
        std::cout << "No next move...\n";
        winner();
    }
    else{
        if(current_move){
        current_move = current_move->next;
        std::cout << "Turn " << current_move->data.id << ": "
        << ((current_move->data.color == 'W') ? "White" : "Black") << " - " << current_move->data.move
        << std::endl << std::endl;}
    }

}

void ChessGameLL::prev_move() {
    if (current_move == head) {
      std::cout << "No previous move....\n\n";
      return;
    } else {
      current_move = current_move->prev;
      std::cout << "Turn " << current_move->data.id << ": "
                << ((current_move->data.color == 'W') ? "White" : "Black") << " - " << current_move->data.move
                << std::endl << std::endl;
    }
  }


  void ChessGameLL::firstmove(){
      current_move = head;
      std::cout << "Turn " << current_move->data.id << ": "
      << ((current_move->data.color == 'W') ? "White" : "Black") << " - " << current_move->data.move
      << std::endl << std::endl;
  }


void ChessGameLL::winner() {
  while (current_move->next) {
    current_move = current_move->next;
  }
  std::cout << "Game ended with " << ((current_move->data.color == 'W') ? "White" : "Black") << " Winning\n\n";
}

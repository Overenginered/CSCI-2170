#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <string>

struct Node {
  std::string m_text;
  Node *next;
};

class LinkedList {
private:
  Node *head;

public:
  LinkedList();
  ~LinkedList();
  Node *get_head();
  bool empty() const;
  void push_back(std::string text);
  void display() const;
  void display_reverse(Node *curr) const;
  void display_recursive(Node *curr) const;
};

#endif
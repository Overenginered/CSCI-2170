#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

struct Node {
  // some data variables and such
  int data;
  // Pointer to another Node
  Node *next;
};

class LinkedList {
private:
  Node *head; // pointer to first item in list
  Node *tail; // pointer to last item in list
  // TODO:
  // find's a value in a list
  // returns a nullptr if it wasn't found
  // returns a pointer to the item if it was found
  Node *find(int value);

public:
  LinkedList();               // How do I initialize my object?
  void push_back(int value);  // add elements to the end of our LL
  void print() const;         // print all elements
  bool empty() const;         // am i empty
  void push_front(int value); // push to front
  // TODO
  // given an integer value, this function should
  // remove the first instance of the value it finds
  // in the list, or print an error message if
  // it could not remove the value
  void remove_value(int value);
};

#endif
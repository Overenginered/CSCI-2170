#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

bool LinkedList::empty() const {
  if (head == nullptr)
    return true;
  return false;
}

void LinkedList::print() const {
  if (empty()) {
    std::cout << "ERROR: empty list...\n";
    return;
  }

  std::cout << "Data:\n";
  Node *curr = head;
  while (curr != nullptr) {
    std::cout << curr->data << '\n';
    curr = curr->next;
  }
  std::cout << '\n';
}

void LinkedList::push_front(int value) {
  Node *newNode = new Node;
  newNode->data = value;
  newNode->next = head;

  if (empty()) {
    head = newNode;
    tail = newNode;
    return;
  }

  head = newNode;
}

void LinkedList::push_back(int value) {
  Node *newNode = new Node;
  newNode->data = value;
  newNode->next = nullptr;

  if (empty()) {
    head = newNode;
    tail = newNode;
    return;
  }
  tail->next = newNode;
  tail = newNode;
}

void LinkedList::remove_value(int value) {
  // TODO: IMPLEMENT THIS FUNCTION
  Node *prev = find(value);
  if (prev == nullptr) {
    std::cout << "ERROR: " << value << " not found, could not remove...\n";
    return;
  }
  Node *curr = prev->next;


    if(prev == head){
         head = curr->next;
         delete curr;
         return;
     }
    
      prev->next = curr->next;

  if (curr == tail) {
    tail = prev;
  }
  delete curr;
}

Node *LinkedList::find(int value) {
  // TODO: find the value in the list,
  // return nullptr if it isn't found
  // otherwise return a pointer to the
  // value in the list
  Node *curr = head;
  Node *prev = nullptr;
  while (curr != nullptr) {
    if (curr->data == value) {
        //std::cout << curr->data;
        if(prev == nullptr){
            return nullptr;}
        
      return prev;
    }
    prev = curr;
    curr = curr->next;
  }
  return nullptr;
}

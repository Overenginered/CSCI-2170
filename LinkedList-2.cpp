#include "LinkedList.h"
#include <iostream>
#include <string>

LinkedList::LinkedList() {
  head = nullptr; // make sure head is null
}
bool LinkedList::empty() const {
  // it's empty if head is a nullptr
  return head == nullptr;
}
void LinkedList::push_back(std::string text) {
  // Create a new Node and store the text in it
  Node *to_add = new Node;
  to_add->m_text = text;
  to_add->next = nullptr;
  // If it's empty, make the head point to the new node
  if (empty()) {
    head = to_add;
    return;
  }
  // otherwise, traverse to the end
  Node *curr{head};

  while (curr->next != nullptr) {
    curr = curr->next;
  }
  // connect the last node to the new one
  curr->next = to_add;
}

Node *LinkedList::get_head() { return head; }

void LinkedList::display() const {
  // get a temporary pointer to start at head
  Node *curr{head};
  // as long as it isn't a null ptr
  while (curr != nullptr) {
    // display the text
    std::cout << curr->m_text << " ";
    // move current to the next node in the list
    curr = curr->next;
  }
}

// TODO: Implement display_recursive to print the list
//       forward using recursion
void LinkedList::display_recursive(Node *curr)const{
  
    if(curr == nullptr){

        return;
    } else{
        std::cout << curr->m_text << " ";
        display_recursive(curr->next);
    }

    
    
}

// TODO: Implement display_reverse using recursion
void LinkedList::display_reverse(Node *curr)const{

    if(curr == nullptr){
        return;   
    }else{
        display_reverse(curr->next);
        std::cout << curr->m_text << " ";
    }
    
    
}
// TODO: Implement the destructor for the Linked List using an
//       iterative (NOT recursive approach)
LinkedList::~LinkedList(){
      Node *curr, *nextone;

    curr = head;
    while(curr){
        nextone = curr->next;
        delete curr;
        curr = nextone;
    }
}
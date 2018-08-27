#include "list.h"

namespace list {
  // CREATION AND DELETION FUNCTIONS.  DO THESE FIRST!
  LinkedList* create() {
    // Create an empty linked list on the heap.
    return 0;
  }

  LinkedList* create(const char* data) {
    // Create a linked list on the heap.
    // It should contain the characters from cstring data.
    // Don't include the null character.
    return 0;
  }

  void destroy(LinkedList* l) {
    // Delete a linked list.
    // Make sure you clean up all the nodes!
    // If the pointer is null, do nothing.
  }



  // BASIC OPERATIONS.  THESE SHOULD BE FAIRLY SIMPLE.
  char at(const LinkedList& l, int index) {
    // Return the character at index.
    // If index is out of bounds, return the null character.
    return '~';
  }

  int length(const LinkedList& l) {
    // Return the number of elements in the list.
    return -42;
  }

  char pop(LinkedList& l) {
    // Remove the node at the end of the list and return its data.
    // If the list is empty, return the null character.
    return '~';
  }

  void push(LinkedList& l, char c) {
    // Insert a new node at the end of the list.
  }

  char shift(LinkedList& l) {
    // Remove the node at the start of the list and return its data.
    // If the list is empty, return the null character.
    return '~';
  }

  void unshift(LinkedList& l, char c) {
    // Insert a new node at the start of the list.
  }



  // MORE COMPLICATED OPERATIONS.  GOOD LUCK!
  void append(LinkedList& l, const LinkedList& other) {
    // Copy the contents of other onto the end of the list.
  }

  char* cstring(const LinkedList& l) {
    // Return a new cstring containing the characters from the list.
    return 0;
  }

  void erase(LinkedList& l, int index, int count) {
    // Remove count nodes, starting at index.
    // If index is out of bounds, do nothing.
    // If count is too big, remove until the end of the list.
  }

  void eraseAll(LinkedList& l, char c) {
    // Remove all nodes containing the given value.
  }

  int find(const LinkedList& l, char c, int start) {
    // Return the index of the first occurrence of c.
    // Start your search at index start.
    // If you can't find c, return -1.
    return -42;
  }

  void insert(LinkedList& l, char c, int index) {
    // Insert a new element at index.
  }
}

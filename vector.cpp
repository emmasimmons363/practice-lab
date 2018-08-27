#include "vector.h"

void resize(Vector& v, int size) {
  // Resize a vector's data array (if necessary).
  // This method is not required, but you may find it useful.
}

namespace vector {
  // CREATION AND DELETION FUNCTIONS.  DO THESE FIRST!
  Vector* create() {
    // Create an empty vector on the heap.
    return 0;
  }

  Vector* create(const char* data) {
    // Create a vector on the heap.
    // It should contain the characters from cstring data.
    // Don't include the null character.
    return 0;
  }

  void destroy(Vector* l) {
    // Delete a vector.
    // Make sure you clean up the data array!
    // If the pointer is null, do nothing.
  }



  // BASIC OPERATIONS.  THESE SHOULD BE FAIRLY SIMPLE.
  char at(const Vector& v, int index) {
    // Return the character at index.
    // If index is out of bounds, return the null character.
    return '~';
  }

  int length(const Vector& v) {
    // Return the number of elements in the vector.
    return -42;
  }

  char pop(Vector& v) {
    // Remove and return the element at the end of the vector.
    // If the vector is empty, return the null character.
    return '~';
  }

  void push(Vector& v, char c) {
    // Insert a new element at the end of the vector.
  }

  char shift(Vector& v) {
    // Remove and return the element at the start of the vector.
    // If the vector is empty, return the null character.
    return '~';
  }

  void unshift(Vector& v, char c) {
    // Insert a new element at the start of the vector.
  }



  // MORE COMPLICATED OPERATIONS.  GOOD LUCK!
  void append(Vector& v, const Vector& other) {
    // Copy the contents of other onto the end of the vector.
  }

  char* cstring(const Vector& v) {
    // Return a new cstring containing the characters from the vector.
    return 0;
  }

  void erase(Vector& v, int index, int count) {
    // Remove count elements, starting at index.
    // If index is out of bounds, do nothing.
    // If count is zero or negative, do nothing.
    // If count is too big, remove until the end of the vector.
  }

  void eraseAll(Vector& v, char c) {
    // Remove all elements with the given value.
  }

  int find(const Vector& v, char c, int start) {
    // Return the index of the first occurrence of c.
    // Start your search at index start.
    // If you can't find c, return -1.
    return -42;
  }

  void insert(Vector& v, char c, int index) {
    // Insert a new element at index.
    // If index is equal to the size, append the element.
    // If index is negative or greater than the size, do nothing.
  }
}

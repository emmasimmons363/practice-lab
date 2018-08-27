#include "vector.h"

#include <cstring>

void resize(Vector& v, int size) {
  int cap = 4;
  while(cap < size) {
    cap *= 2;
  }

  if(cap != v.capacity) {
    char* temp = v.data;
    v.data = new char[cap];

    for(int i = 0; i < v.length; ++i) {
      v.data[i] = temp[i];
    }

    v.capacity = cap;
    delete [] temp;
  }
}

void resize(Vector& v) {
  resize(v, v.length);
}

namespace vector {
  // CREATION AND DELETION FUNCTIONS.  DO THESE FIRST!
  Vector* create() {
    // Create an empty vector on the heap.
    return create("");
  }

  Vector* create(const char* data) {
    // Create a vector on the heap.
    // It should contain the characters from cstring data.
    // Don't include the null character.
    int cap = 4;
    int len = std::strlen(data);
    while(cap < len) cap *= 2;

    Vector* v = new Vector;
    v->data = new char[cap];
    std::memcpy(v->data, data, len);
    v->capacity = cap;
    v->length = len;
    return v;
  }

  void destroy(Vector* v) {
    // Delete a vector.
    // Make sure you clean up the data array!
    // If the pointer is null, do nothing.
    if(v == NULL) return;
    delete [] v->data;
    delete v;
  }



  // BASIC LIST OPERATIONS.  THESE SHOULD BE FAIRLY SIMPLE.
  char at(const Vector& v, int index) {
    // Return the character at index.
    // If index is out of bounds, return the null character.
    if(index < 0 || index >= v.length) return '\0';
    return v.data[index];
  }

  int length(const Vector& v) {
    // Return the number of elements in the vector.
    return v.length;
  }

  char pop(Vector& v) {
    // Remove and return the element at the end of the vector.
    // If the vector is empty, return the null character.
    if(v.length < 1) return '\0';
    char result = v.data[v.length - 1];
    erase(v, v.length - 1, 1);
    return result;
  }

  void push(Vector& v, char c) {
    // Insert a new element at the end of the vector.
    insert(v, c, v.length);
  }

  char shift(Vector& v) {
    // Remove and return the element at the start of the vector.
    // If the vector is empty, return the null character.
    if(v.length < 1) return '\0';
    char result = v.data[0];
    erase(v, 0, 1);
    return result;
  }

  void unshift(Vector& v, char c) {
    // Insert a new element at the start of the vector.
    insert(v, c, 0);
  }



  // MORE COMPLICATED LIST OPERATIONS.  GOOD LUCK!
  void append(Vector& v, const Vector& other) {
    // Copy the contents of other onto the end of the vector.
    resize(v, v.length + other.length);

    int src = 0;
    int dst = v.length;
    while(src < other.length) {
      v.data[dst] = other.data[src];
      src += 1;
      dst += 1;
    }

    v.length += other.length;
  }

  char* cstring(const Vector& v) {
    // Return a new cstring containing the characters from the vector.
    char* result = new char[v.length + 1];
    std::memcpy(result, v.data, v.length);
    result[v.length] = '\0';
    return result;
  }

  void erase(Vector& v, int index, int count) {
    // Remove count elements, starting at index.
    // If index is out of bounds, do nothing.
    // If count is too big, remove until the end of the vector.
    if(index < 0 || index >= v.length || count < 1) {
      return;
    }

    int dst = index;
    int src = index + count;
    while(src < v.length) {
      v.data[dst] = v.data[src];
      dst += 1;
      src += 1;
    }

    v.length = dst;
    resize(v);
  }

  void eraseAll(Vector& v, char c) {
    // Remove all elements with the given value.
    int dst = 0;
    for(int src = 0; src < v.length; ++src) {
      if(v.data[src] != c) {
        v.data[dst] = v.data[src];
        dst += 1;
      }
    }

    v.length = dst;
    resize(v);
  }

  int find(const Vector& v, char c, int start) {
    // Return the index of the first occurrence of c.
    // Start your search at index start.
    // If you can't find c, return -1.
    if(start < 0) return -1;
    for(int i = start; i < v.length; ++i) {
      if(v.data[i] == c) return i;
    }

    return -1;
  }

  void insert(Vector& v, char c, int index) {
    // Insert a new element at index.
    if(index < 0 || index > v.length) {
      return;
    }

    resize(v, v.length + 1);
    for(int i = v.length; i > index; --i) {
      v.data[i] = v.data[i - 1];
    }

    v.data[index] = c;
    v.length += 1;
  }
}

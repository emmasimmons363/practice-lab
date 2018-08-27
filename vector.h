#ifndef VECTOR_H
#define VECTOR_H

struct Vector {
  int length;
  int capacity;
  char* data;
};

namespace vector {
  Vector* create();
  Vector* create(const char* data);
  void    destroy(Vector* v);

  char  at(const Vector& v, int index);
  char  pop(Vector& v);
  void  push(Vector& v, char c);
  int   length(const Vector& v);
  char  shift(Vector& v);
  void  unshift(Vector& v, char c);

  void  append(Vector& v, const Vector& other);
  char* cstring(const Vector& v);
  void  erase(Vector& v, int index, int count = 1);
  void  eraseAll(Vector& v, char c);
  int   find(const Vector& v, char c, int start = 0);
  void  insert(Vector& v, char c, int index);
}

#endif

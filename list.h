#ifndef LIST_H
#define LIST_H

struct Node {
  char  data;
  Node* next;
};

struct LinkedList {
  Node* head;
  Node* tail;
};

namespace list {
  LinkedList* create();
  LinkedList* create(const char* data);
  void        destroy(LinkedList* l);

  char  at(const LinkedList& l, int index);
  char  pop(LinkedList& l);
  void  push(LinkedList& l, char c);
  int   length(const LinkedList& l);
  char  shift(LinkedList& l);
  void  unshift(LinkedList& l, char c);

  void  append(LinkedList& l, const LinkedList& other);
  char* cstring(const LinkedList& l);
  void  erase(LinkedList& l, int index, int count = 1);
  void  eraseAll(LinkedList& l, char c);
  int   find(const LinkedList& l, char c, int start = 0);
  void  insert(LinkedList& l, char c, int index);
}


#endif

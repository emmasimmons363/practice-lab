#include "list.h"
#include "vector.h"

#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

int ERRORS = 0;

void testimpl(char value, char target, int line) {
  if(value != target) {
    std::cout << "  Line " << std::setw(3) << line << ": Expected '" << target << "' but got '" << value << "'\n";
    ERRORS += 1;
  }
}

void testimpl(int value, int target, int line) {
  if(value != target) {
    std::cout << "  Line " << std::setw(3) << line << ": Expected " << target << " but got " << value << "\n";
    ERRORS += 1;
  }
}

void testimpl(const char* value, const char* target, int line) {
  if(strcmp(value, target) != 0) {
    std::cout << "  Line " << std::setw(3) << line << ": Expected \"" << target << "\" but got \"" << value << "\"\n";
    ERRORS += 1;
  }
}

void testimpl(const LinkedList* l, const char* target, int line) {
  if(!l) {
    std::cout << "  Line " << std::setw(3) << line << ": Null pointer given.\n";
    ERRORS += 1;
    return;
  }

  std::string str;
  Node* prev = NULL;
  Node* curr = l->head;
  while(curr != NULL) {
    str += curr->data;
    prev = curr;
    curr = curr->next;
  }

  if(str != target) {
    std::cout << "  Line " << std::setw(3) << line << ": Expected \"" << target << "\" but got \"" << str << "\"\n";
    ERRORS += 1;
    return;
  }

  if(prev != l->tail) {
    std::cout << "  Line " << std::setw(3) << line << ": Incorrect tail pointer.\n";
    ERRORS += 1;
    return;
  }
}

void testimpl(const Vector* v, const char* target, int line) {
  if(!v) {
    std::cout << "  Line " << std::setw(3) << line << ": Null pointer given.\n";
    ERRORS += 1;
    return;
  }

  std::string str(v->data, v->data + v->length);
  if(str != target) {
    std::cout << "  Line " << std::setw(3) << line << ": Expected \"" << target << "\" but got \"" << str << "\"\n";
    ERRORS += 1;
    return;
  }

  int len = str.length();
  if(v->length != len) {
    std::cout << "  Line " << std::setw(3) << line << ": Expected length " << len << " but got " << v->length << "\n";
    ERRORS += 1;
    return;
  }

  int cap = 4;
  while(cap < len) cap *= 2;
  if(v->capacity != cap) {
    std::cout << "  Line " << std::setw(3) << line << ": Expected capacity " << cap << " but got " << v->capacity << "\n";
    ERRORS += 1;
    return;
  }

}

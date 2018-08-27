#include "list.h"
#include "vector.h"
#include "test-functions.h"

#include <cstring>
#include <iostream>
using namespace WRAP;

// Preprocessor magic.
#define Q(X) #X
#define QUOTE(X) Q(X)

// Preprocessor macro for automatic line numbering:
#define test(v, t) testimpl(v, t, __LINE__)

// Test functions are in alphabetical order.
// main() is at the bottom of the file.

void test_append() {
  std::cout << "Testing " QUOTE(WRAP) "::append()\n";

  TYPE* t1 = create();
  TYPE* t2 = create("Ignorance");
  TYPE* t3 = create(" is ");
  TYPE* t4 = create("Strength");
  TYPE* t5 = create();

  append(*t1, *t5);
  test(t1, "");

  append(*t1, *t2);
  test(t1, "Ignorance");

  append(*t1, *t3);
  test(t1, "Ignorance is ");

  append(*t1, *t5);
  test(t1, "Ignorance is ");

  append(*t1, *t4);
  test(t1, "Ignorance is Strength");

  append(*t1, *t5);
  test(t1, "Ignorance is Strength");
  test(t2, "Ignorance");
  test(t3, " is ");
  test(t4, "Strength");
  test(t5, "");

  destroy(t1);
  destroy(t2);
  destroy(t3);
  destroy(t4);
  destroy(t5);
}

void test_at() {
  std::cout << "Testing " QUOTE(WRAP) "::at()\n";

  TYPE* t = create("The quick brown fox...");
  test(at(*t,   0), 'T');
  test(at(*t,   5), 'u');
  test(at(*t,  18), 'x');

  test(at(*t, -31), '\0');
  test(at(*t, 567), '\0');
  destroy(t);
}

void test_create() {
  std::cout << "Testing " QUOTE(WRAP) "::create()\n";

  TYPE* t1 = create();
  test(t1, "");
  destroy(t1);

  TYPE* t2 = create("");
  test(t2, "");
  destroy(t2);

  TYPE* t3 = create("?");
  test(t3, "?");
  destroy(t3);

  TYPE* t4 = create("Hello, world!");
  test(t4, "Hello, world!");
  destroy(t4);
}

void test_cstring() {
  std::cout << "Testing " QUOTE(WRAP) "::cstring()\n";

  TYPE* t1 = create();
  char* s1 = cstring(*t1);
  test(s1, "");
  delete [] s1;
  destroy(t1);

  TYPE* t2 = create("Hullabaloo!");
  char* s2 = cstring(*t2);
  test(s2, "Hullabaloo!");
  delete [] s2;
  destroy(t2);
}

void test_destroy() {
  std::cout << "Testing " QUOTE(WRAP) "::destroy()\n";

  TYPE* t1 = create();
  destroy(t1);

  TYPE* t2 = create("Archipelago!?");
  destroy(t2);

  TYPE* t3 = 0;
  destroy(t3);
}

void test_erase() {
  std::cout << "Testing " QUOTE(WRAP) "::erase()\n";

  TYPE* t = create("Goodbye cruel world...");
  erase(*t, -1, 42);
  test(t, "Goodbye cruel world...");

  erase(*t, 137, 4);
  test(t, "Goodbye cruel world...");

  erase(*t, 4, -3);
  test(t, "Goodbye cruel world...");

  erase(*t, -1, 42);
  test(t, "Goodbye cruel world...");

  erase(*t, 7, 6);
  test(t, "Goodbye world...");

  erase(*t, 14, 50);
  test(t, "Goodbye world.");

  erase(*t, 3, 11);
  test(t, "Goo");
  destroy(t);
}

void test_eraseAll() {
  std::cout << "Testing " QUOTE(WRAP) "::eraseAll()\n";

  TYPE* t = create("Hello, world!");
  eraseAll(*t, 'z');
  test(t, "Hello, world!");

  eraseAll(*t, 'l');
  test(t, "Heo, word!");

  eraseAll(*t, 'H');
  test(t, "eo, word!");

  eraseAll(*t, '!');
  test(t, "eo, word");
  destroy(t);
}

void test_find() {
  std::cout << "Testing " QUOTE(WRAP) "::find()\n";

  TYPE* t = create("Hello, world!");
  test(find(*t, 'z', 0), -1);
  test(find(*t, 'l', 0),  2);
  test(find(*t, 'l', 2),  2);
  test(find(*t, 'l', 3),  3);
  test(find(*t, 'l', 4), 10);
  destroy(t);
}

void test_insert() {
  std::cout << "Testing " QUOTE(WRAP) "::insert()\n";


}

void test_pop() {
  std::cout << "Testing " QUOTE(WRAP) "::pop()\n";

  TYPE* t = create("Pox!");
  test(pop(*t), '!');
  test(t, "Pox");

  test(pop(*t), 'x');
  test(t, "Po");

  test(pop(*t), 'o');
  test(t, "P");

  test(pop(*t), 'P');
  test(t, "");

  test(pop(*t), '\0');
  test(t, "");
  destroy(t);
}

void test_push() {
  std::cout << "Testing " QUOTE(WRAP) "::push()\n";

  TYPE* t = create();
  push(*t, 'B');
  test(t, "B");

  push(*t, 'o');
  test(t, "Bo");

  push(*t, 'x');
  test(t, "Box");
  destroy(t);
}

void test_length() {
  std::cout << "Testing " QUOTE(WRAP) "::length()\n";

  TYPE* t1 = create();
  test(length(*t1), 0);
  destroy(t1);

  TYPE* t2 = create("Socks!");
  test(length(*t2), 6);
  destroy(t2);
}

void test_shift() {
  std::cout << "Testing " QUOTE(WRAP) "::shift()\n";

  TYPE* t = create("Cat?");
  test(shift(*t), 'C');
  test(t, "at?");

  test(shift(*t), 'a');
  test(t, "t?");

  test(shift(*t), 't');
  test(t, "?");

  test(shift(*t), '?');
  test(t, "");

  test(shift(*t), '\0');
  test(t, "");
  destroy(t);
}

void test_unshift() {
  std::cout << "Testing " QUOTE(WRAP) "::unshift()\n";

  TYPE* t = create();
  unshift(*t, 'A');
  test(t, "A");

  unshift(*t, 'Z');
  test(t, "ZA");

  unshift(*t, 'Z');
  test(t, "ZZA");

  unshift(*t, 'I');
  test(t, "IZZA");

  unshift(*t, 'P');
  test(t, "PIZZA");
  destroy(t);
}


int main(int argc, char* argv[]) {
  // Creation and deletion.
  test_create();
  test_destroy();

  if(ERRORS != 0) {
    std::cout << "\nYou have errors in your create() and/or destroy() functions.\n";
    std::cout << "These need to work before the other tests can run.\n\n";
    return 0;
  }

  // Basic operations.
  test_at();
  test_pop();
  test_push();
  test_length();
  test_shift();
  test_unshift();

  bool runall = (argc > 1 && strcmp(argv[1], "all") == 0);
  if(ERRORS != 0 && !runall) {
    std::cout << "\nYou aren't done with the basic operations yet.\n";
    std::cout << "The tests for complicated operations are hidden by default in this case.\n";
    std::cout << "Run `" << argv[0] << " all` if you want to run them anyway.\n\n";
    return 0;
  }

  // Complicated operations.
  test_append();
  test_cstring();
  test_erase();
  test_eraseAll();
  test_find();
  test_insert();

  if(ERRORS == 0) {
    std::cout << "\nCongratulations!  All " QUOTE(WRAP) " tests passed!\n\n";
  }

  return 0;
}

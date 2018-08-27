# Practice Lab

For those of you  who want some more coding practice before the final,  here are
some practice problems. The linked list and the vector can both be used to store
strings (sequences of characters). This "lab" explores how those two versions of
strings would work (the real `std::string ` implementation is quite close to the
`Vector` implementation here).

The two types are defined in  `list.h` and `vector.h`.  Your job is to implement
the functions in  `list.cpp` and  `vector.cpp`.  Tests are written for you  (see
`tests.cpp`  -  a bit of preprocessor magic allows the same tests to run on both
vectors and linked lists).

Good luck!


## The Linked List

The  linked list  works  just like the one from class,  but contains  characters
instead of integers.  The list container involves two types:

- The `LinkedList`  contains a `head` pointer and a `tail` pointer.  These point
  to the first and last `Node`s in the list, respectively. If the list is empty,
  both `head` and `tail` should be `NULL`.
- The `Node` contains a `data` member,  which holds the character stored in that
  `Node`,  and a `next` pointer,  which points to the next  `Node`  in the list.
  The last `Node` in the list should have its `next` pointer set to `NULL`.

Implement the functions in  `list.cpp`,  and run  `make test-list`  to test your
implementation.


## The Vector

The vector is a type of "dynamic array." Its elements are stored contiguously in
memory,  but it can grow and shrink to fit its contents.  There is only one type
here: the `Vector`.  It contains:

- An integer `length`, the number of elements stored in the `Vector`.
- An integer `capacity`, the space available in the current `data` array.
- A character pointer `data`,  which points to a dynamically  allocated array of
  characters.  All data is stored here.  If the array is  too big  or too small,
  reallocate it and copy everything into the new array. Make sure you delete the
  old one!

The tests  expect the following constraints on the `data` array  (there are edge
cases where this can be very inefficient, but we'll ignore those):

- `capacity` must always be a power of two.
- `capacity` must always be four of greater (even if the vector is empty).
- `capacity` must be the smallest power of two that can fit the data (but it can
  never be less than four).

Implement the functions in `vector.cpp`, and run `make test-vector` to test your
implementation.

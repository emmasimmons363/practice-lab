#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

void testimpl(char value, char target, int line);
void testimpl(int value, int target, int line);
void testimpl(const char* value, const char* target, int line);
void testimpl(const LinkedList* l, const char* target, int line);
void testimpl(const Vector* v, const char* target, int line);

extern int ERRORS;

#endif

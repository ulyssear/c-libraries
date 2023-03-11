#include <assert.h>

#include "files.c"

void test_fileread() {
  char * filename = "example.txt";
  int size;
  char * content = fileread(filename, & size), * expected = "Hello";
  assert(size > 4);
  content = lsubstr(content, 5);
  assert(0 == strequals(content, expected));
  free(content);
}

void test_filewrite() {
  char * filename = "example-write.txt";
  char * content,
    * expected = "Hello, world !";
  int size = strsize(expected);
  filewrite(filename, expected, & size);
  content = fileread(filename, & size);
  content = lsubstr(content, 15);
  assert(0 == strequals(content, "Hello, world !"));
}

void test_printfile() {
  char * filename = "example.txt";
  printfile(filename);
}

int main() {
  test_fileread();
  test_filewrite();
  test_printfile();
  return 0;
}
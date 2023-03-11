#include "strings.c"
#include "bytestrings.c"
#include "uuencode.c"

#include <assert.h>

void test_uuencode() {
  char * s = "Hello, world!";
  char * uus = uuencode(s);
  char * s2 = uudecode(uus);
  assert(strequals(s, s2) == 0);
}

int main() {
  test_uuencode();
  return 0;
}
#include "strings.c"
#include "bytestrings.c"

#include <assert.h>

void test_int2bs() {
  char * bs = int2bs(65);
  assert(0 == strequals(bs, "01000001"));
}

void test_s2bs() {
  char * bs = s2bs("A");
  assert(0 == strequals(bs, "01000001"));
}

void test_bs2c() {
  char c = bs2c("01000001");
  assert(c == 'A');
}

void test_bs2s() {
  char * s = lsubstr(bs2s("0100000101000010", 8), 2);
  assert(0 == strequals(s, "AB"));
}

int main() {
  test_int2bs();
  test_s2bs();
  test_bs2c();
  test_bs2s();
  return 0;
}
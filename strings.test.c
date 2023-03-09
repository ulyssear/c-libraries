#include <assert.h>
#include "strings.c"

void test_charstring() {
  unsigned char * str = charstring(0);
  assert(str[0] == 0);
  free(str);
}

void test_string() {
  char * str = string();
  assert(str[0] == 0);
  free(str);
}

void test_strsize() {
  char * str = string();
  assert(strsize(str) == 0);
  free(str);
}

void test_append_char() {
  char * str = string();
  int size = 0;
  str = append_char(str, & size, 'a');
  assert(str[0] == 'a');
  assert(str[1] == 0);
  assert(size == 1);
  free(str);
}

void test_concat_str() {
  char * str = string();
  int size = 0;
  str = concat_str(str, "a");
  assert(str[0] == 'a');
  assert(str[1] == 0);
  free(str);
}

void test_pad_left() {
  char * str = string();
  int size = 0;
  str = append_char(str, & size, 'a');
  str = pad_left(2, str, & size);
  assert(str[0] == '0');
  assert(str[1] == 'a');
  assert(str[2] == 0);
  assert(size == 2);
  free(str);
}

void test_pad_right() {
  char * str = string();
  int size = 0;
  str = append_char(str, & size, 'a');
  str = pad_right(2, str, & size);
  assert(str[0] == 'a');
  assert(str[1] == '0');
  assert(str[2] == 0);
  assert(size == 2);
  free(str);
}

void test_replace_all() {
  char * str = string();
  int size = 0;
  str = concat_str(str, "a");
  str = replace_all(str, "a", "b", & size);
  assert(str[0] == 'b');
  assert(str[1] == 0);
  assert(size == 1);
  free(str);
}

void test_ltrim() {
  char * str = string();
  int size = 0;
  str = concat_str(str, " a");
  str = ltrim(str, & size);
  assert(str[0] == 'a');
  assert(str[1] == 0);
  assert(size == 1);
  free(str);
}

void test_rtrim() {
  char * str = "a  ";
  int size = strsize(str);
  str = rtrim(str, & size);
  assert(str[0] == 'a');
  assert(str[1] == 0);
  assert(size == 1);
  free(str);
}

void test_rsubstr() {
  char * str = string();
  str = concat_str(str, "abc");
  str = rsubstr(str, 2);
  int size = strsize(str);
  assert(str[0] == 'b');
  assert(str[1] == 'c');
  assert(str[2] == 0);
  assert(size == 2);
  free(str);
}

void test_lsubstr() {
  char * str = string();
  str = concat_str(str, "abc");
  str = lsubstr(str, 2);
  int size = strsize(str);
  assert(str[0] == 'a');
  assert(str[1] == 'b');
  assert(str[2] == 0);
  assert(size == 2);
  free(str);
}

void test_strequals() {
  assert(strequals("a", "a") == 0);
  assert(strequals("a", "b") == 1);
}

int main() {
  test_charstring();
  test_string();
  test_strsize();
  test_append_char();
  test_concat_str();
  test_pad_left();
  test_pad_right();
  test_replace_all();
  test_ltrim();
  test_rtrim();
  test_rsubstr();
  test_lsubstr();
  test_strequals();
  return 0;
}
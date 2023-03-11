#include <assert.h>

#include "strings.c"

void test_charstring() {
  char * str = charstring(0);
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

void test_prepend_char() {
  char * str = string();
  int size = 0;
  str = prepend_char(str, & size, 'a');
  assert(str[0] == 'a');
  assert(str[1] == 0);
  assert(size == 1);
  free(str);
}

void test_concat_str() {
  char * str = string();
  str = concat_str(str, "a");
  assert(str[0] == 'a');
  assert(str[1] == 0);
  free(str);
}

void test_pad_left() {
  char * str = "65";
  int size = 0;
  str = pad_left(3, str, & size);
  assert(str[0] == '0');
  assert(str[1] == '6');
  assert(str[2] == '5');
  assert(str[3] == 0);
  assert(size == 3);
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

void test_trim() {
  char * str = " a ";
  int size = strsize(str);
  str = trim(str, & size);
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

void test_substr() {
  char * str = string();
  str = concat_str(str, "abcd");
  str = substr(str, 1, 3);
  int size = strsize(str);
  assert(str[0] == 'b');
  assert(str[1] == 'c');
  assert(str[2] == 0);
  assert(size == 2);
  free(str);
}

void test_i2s() {
  assert(strequals(i2s(42), "42") == 0);
  assert(strequals(i2s(-42), "-42") == 0);
}

void test_strswap() {
  char * str = "Hello World";
  str = strswap(str, 0, 6);
  assert(strequals(str, "Wello Horld") == 0);
}

void test_strreverse() {
  char * str = "Hello World";
  str = strreverse(str);
  assert(strequals(str, "dlroW olleH") == 0);
}

void test_strlindex() {
  char * str = "Hello World";
  char * search = "World";
  char * index = strindex(str, search);
  assert(index == 6);
}

void test_strrindex() {
  char * str = "Hello World World";
  char * search = "World";
  char * index = strrindex(str, search);
  assert(index == 12);
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
  test_substr();
  return 0;
}
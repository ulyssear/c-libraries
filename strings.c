#include <stdlib.h>
#include <stdio.h>

int strsize(char * str) {
  int i = 0;
  while (str[i]) i++;
  return i;
}

char * string() {
  char * s = malloc(1);
  s[0] = 0;
  return s;
}

unsigned char * charstring(int c) {
  unsigned char * s = malloc(2);
  s[0] = c;
  s[1] = 0;
  return s;
}

void printstr(char * str) {
  int a, size = strsize(str);
  for (int i = 0; size > i; i++) printf("%c", str[i]);
  printf("\n");
}

char * concat_str(char * left, char * right) {
  int sl = strsize(left),
    sr = strsize(right),
    i;

  char * str = malloc(sl + sr + 1);

  for (i = 0; sl > i; i++) str[i] = left[i];
  for (i = 0; sr > i; i++) str[sl + i] = right[i];

  str[sl + sr] = 0;

  return str;
}

char * append_char(char * str, int * size, char to_append) {
  char * cs = charstring(to_append);
  str = concat_str(str, cs);
  ( * size) = ( * size) + 1;
  return str;
}

char * prepend_char(char * str, int * size, char to_prepend) {
  char * cs = charstring(to_prepend);
  str = concat_str(cs, str);
  ( * size) = ( * size) + 1;
  return str;
}

char * pad_left(int base, char * str, int * size) {
  int b, i;
  if ((b = * size % base)) {
    i = b - 1;
    while (-1 < i--) str = concat_str("0", str);
    ( * size) = strsize(str);
  }

  return str;
}

char * pad_right(int base, char * str, int * size) {
  int b, i, l;
  if ((b = * size % base)) {
    l = b;
    i = 0;
    while (l > i++) str = concat_str(str, "0");
    ( * size) = strsize(str);
  }

  return str;
}

char * replace_all(char * origin, char * search, char * replacement, int * str_size) {
  int limit = 1000, a = 0, b = 0, i, not_done = 1, search_size = strsize(search), replacement_size = strsize(replacement);
  char * nstr = string(), c;

  while (0 < (c = origin[a++])) {
    if (0 > limit--) break;
    if (c == search[b]) {
      if (search_size == b + 1) {
        nstr = concat_str(nstr, replacement);
        ( * str_size) += replacement_size;
        b = 0;
        continue;
      }
      b++;
      continue;
    }
    if (0 < not_done) not_done = 0;
    if (0 < b) {
      for (i = 0; b > i; i++) {
        nstr = append_char(nstr, str_size, search[i]);
        ( * str_size) ++;
      }
      b = 0;
    }
    nstr = append_char(nstr, str_size, c);
    ( * str_size) ++;
  }

  return nstr;
}

char * ltrim(char * str, int * size) {
  int limit = 500, a = -1, b = 0, i, not_done = 1;
  char * nstr = string(), c;
  while (0 < (c = str[++a])) {
    if (0 > limit--) break;
    if (' ' == c && not_done) continue;
    if (0 < not_done) not_done = 0;
    nstr = append_char(nstr, & b, c);
  }
  ( * size) = strsize(nstr);
  return nstr;
}

char * rtrim(char * str, int * size) {
  int a = * size, b = 0, i, not_done = 1, limit = a;
  char * nstr = string(), c;
  while (0 < a--) {
    if (0 > limit--) break;
    if (' ' == str[a] && not_done) continue;
    if (0 < not_done) not_done = 0;
    nstr = prepend_char(nstr, size, str[a]);
  }
  ( * size) = strsize(nstr);
  return nstr;
}

char * rsubstr(char * str, int size) {
  char * s_c = charstring(0), * nstr = string();
  int i, l = strsize(str);
  if (l < size) size = l;
  for (i = size - 1; - 1 < i; i--) {
    nstr = prepend_char(nstr, & l, str[i + 1]);
  }
  return nstr;
}

char * lsubstr(char * str, int size) {
  char * nstr = string();
  int i, l = strsize(str), j;
  if ((l - size) < 1) size = l;
  i = -1;
  while (size - 1 > i++) {
    nstr = append_char(nstr, & j, str[i]);
  }
  return nstr;
}

int strequals(char * a, char * b) {
  int as = strsize(a), bs = strsize(b);
  int i = -1;
  if (as != bs) return 1;
  while (as > i++) {
    if (as < i || bs < i) break;
    if (a[i] != b[i]) return 1;
  }
  return 0;
}

char * substr(char * str, int start, int end) {
  char * nstr = string();
  int i, l = strsize(str), j;
  if (end < start) {
    i = start;
    start = end;
    end = i;
  }
  if (end > l) end = l;
  if (start > l) start = l;
  i = start - 1;
  while (end - 1 > i++) {
    nstr = append_char(nstr, & j, str[i]);
  }
  return nstr;
}
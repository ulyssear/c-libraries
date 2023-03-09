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

unsigned char * charstring() {
  unsigned char * s = malloc(2);
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
  char * cs = charstring();
  cs[0] = to_append;
  str = concat_str(str, cs);
  ( * size) = ( * size + 1);
  return str;
}

char * pad_left(int base, char * str, int * size) {
  int b, i;
  if ((b = * size % base)) {
    i = b;
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
  int size = * str_size,
    i, c, a = 0, j, k,
    size_search = strsize(search),
    size_r = strsize(replacement);

  char * str = string();
  for (i = 0; size > i; i++) {
    for (j = 0; size_search > j; j++)
      if (search[j] != origin[i + j]) break;

    if (j != size_search) {
      a++;
      str = append_char(str, & a, origin[i]);
      continue;
    }

    for (k = 0; size_r > k; k++) {
      a++;
      str = append_char(str, & a, replacement[a]);
    }

    i += size_search - 1;
  }

  ( * str_size) = a;

  return str;
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
  return nstr;
}

char * rtrim(char * str, int * size) {
  int limit = 500, a = * size, b = 0, i, not_done = 1;
  char * nstr = string(), c,
    * sub_str = charstring();

  while (0 < a) {
    c = str[--a];
    if (0 > limit--) break;
    if (' ' == c && not_done) continue;
    if (0 < not_done) not_done = 0;
    sub_str[0] = c;
    nstr = concat_str(sub_str, nstr);
  }

  ( * size) = strsize(nstr);
  return nstr;
}

char * rsubstr(char * str, int size) {
  char * s_c = charstring(), * nstr = string();
  int i, l = strsize(str);
  if (l < size) size = l;
  for (i = size - 1; - 1 < i; i--) {
    s_c[0] = str[i + 1];
    nstr = concat_str(s_c, nstr);
  }

  return nstr;
}

char * lsubstr(char * str, int size) {
  char * nstr = string();
  int i, l = strsize(str), j;
  if ((l - size) < 1) size = l;
  i = 0;
  while (size - 1 > i++) {
    nstr = append_char(nstr, & j, str[i + 1]);
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

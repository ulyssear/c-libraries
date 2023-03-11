#include "strings.c"

char * int2bs(int i) {
  char * bs = string();
  int j = 0;
  while (i > 0) {
    bs = append_char(bs, & j, '0' + (i % 2));
    i /= 2;
  }
  return pad_left(8, bs, & j);
}

char * s2bs(char * s) {
  int size = strsize(s);
  char * bs = string(), * bs2;
  for (int i = 0; i < size; i++) {
    bs2 = int2bs(s[i]);
    bs = concat_str(bs, bs2);
  }
  size = strsize(s);
  return pad_left(8, bs, & size);
}

char bs2c(char * bs) {
  int size = strsize(bs);
  bs = pad_left(8, bs, & size);
  int c = 0, i;
  for (i = 0; i < size; i++) {
    c <<= 1;
    c += bs[i] - '0';
  }
  return c;
}

char * bs2s(char * bs, int base) {
  int size = strsize(bs);
  int i;
  char * s = string();
  char * ch = charstring(0);
  for (i = 0; i < size; i += base) {
    ch[0] = bs2c(substr(bs, i, i + base));
    s = concat_str(s, ch);
  }
  return s;
}
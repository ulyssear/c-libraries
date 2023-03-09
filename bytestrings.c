#include "strings.c"

char * byte() {
  char * bs = malloc(9);
  int i, l = 9;
  for (i = 0; l > i; i++) bs[i] = 0;
  return bs;
}

char * int2bs(int i) {
  char * bs = byte();
  int j = 0;
  while (i > 0) {
    bs[j] = ((i % 2) ? 1 : 0) + '0';
    i = i / 2;
    j++;
  }
  return pad_left(8, bs, & j);
}

char * s2bs(char * s) {
  int size = strsize(s);
  char * bs = string(), * bs2, * ch = charstring(0);
  for (int i = 0; i < size; i++) {
    ch[0] = s[i];
    bs2 = int2bs(s[i]);
    bs = concat_str(bs, bs2);
  }
  return bs;
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
  int i, j, k, l = 0;
  char * s = string();
  char * ch = charstring(0);
  for (i = 0; i < size; i += base) {
    ch[0] = bs2c(substr(bs, i, i + base));
    s = concat_str(s, ch);
  }
  return s;
}
char * uuencode(char * str) {
  int len = strsize(str);
  char * out = malloc(len * 2);
  int i = 0;
  int j = 0;
  while (i < len) {
    char c1 = str[i++];
    char c2 = i < len ? str[i++] : 0;
    char c3 = i < len ? str[i++] : 0;
    out[j++] = ((c1 >> 2) & 0x3f) + ' ';
    out[j++] = (((c1 << 4) | ((c2 >> 4) & 0x0f)) & 0x3f) + ' ';
    out[j++] = (((c2 << 2) | ((c3 >> 6) & 0x03)) & 0x3f) + ' ';
    out[j++] = (c3 & 0x3f) + ' ';
  }
  out[j] = 0;
  return out;
}

char * uudecode(char * str) {
  int len = strsize(str);
  char * out = malloc(len);
  int i = 0;
  int j = 0;
  while (i < len) {
    char c1 = str[i++] - ' ';
    char c2 = str[i++] - ' ';
    char c3 = str[i++] - ' ';
    char c4 = str[i++] - ' ';
    out[j++] = ((c1 << 2) | ((c2 >> 4) & 0x03));
    out[j++] = ((c2 << 4) | ((c3 >> 2) & 0x0f));
    out[j++] = ((c3 << 6) | (c4 & 0x3f));
  }
  out[j] = 0;
  return out;
}
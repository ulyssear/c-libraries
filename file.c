char * fileread(char * filename, int * size) {
  FILE * file;
  file = fopen(filename, "r");
  if (!file) {
    exit(-1);
  }
  int i = 1, c;
  char * content = string();
  while (-1 != (c = fgetc(file))) {
    content = append_char(content, & i, c);
  }
  ( * size) = i;
  return content;
}

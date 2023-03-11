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

void filewrite(char * filename, char * content, int * size) {
  FILE * file;
  file = fopen(filename, "w");
  if (!file) {
    exit(-1);
  }
  int i = -1, l = * size;
  while ( * size > i++) {
    fputc(content[i], file);
    l++;
  }
  fclose(file);
  * size = l;
}

void printfile(char * filename) {
  int size;
  char * content = fileread(filename, & size);
  printstr(content);
  free(content);
}
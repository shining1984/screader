#include <stdio.h>
#include "Index.h"


int main(int argc, char *argv[]) {
  CXIndex Index = clang_createIndex(0,0);
  printf("The scread is working.\n");
  clang_disposeIndex(Index);
  return 0;
}

#include <stdio.h>
void vermelho() {
  printf("\033[0;31m");
}

void vermelho_bold() {
  printf("\033[1;31m");
}

void verde() {
  printf("\033[0;32m");
}

void normal() {
  printf("\033[0m");
}
#include <stdio.h>

#define NORMAL "\033[0m"
#define VERMELHO "\033[0;31m"
#define VERMELHOBOLD "\033[1;31m"
#define VERDE "\033[0;32m"

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
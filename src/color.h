#include <stdio.h>

#define NORMAL "\033[0m"
#define VERMELHO "\033[0;31m"
#define VERMELHOBOLD "\033[1;31m"
#define VERDE "\033[0;32m"

void vermelho() {
  printf(VERMELHO);
}

void vermelho_bold() {
  printf(VERMELHOBOLD);
}

void verde() {
  printf(VERDE);
}

void normal() {
  printf(NORMAL);
}
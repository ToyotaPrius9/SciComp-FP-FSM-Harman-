#include <stdio.h>
#include <unistd.h>



void compute_outputs(int A, int B, int C, int D, int *y1, int *y2) {

    //This Below Is The Derived Boolean Equation Put Into Play :)
  *y1 = !B & C | C & !D | A & B;
  *y2 = D | A & B & !C;
    // Anything Below This Point Solely Exists For Visualization 
  
  
  if (*y1 == 0 && *y2 == 0) {
    printf("\033[37m");
    printf(" ____ \n"
           "|    |\n"
           "| P  |\n"
           "|____|\n");
  } else if (*y1 == 0 && *y2 == 1) {
    printf("\033[31m");
    printf(" ____ \n"
           "|    |\n"
           "| R  |\n"
           "|____|\n");
  } else if (*y1 == 1 && *y2 == 0) {
    printf("\033[32m");
    printf(" ____ \n"
           "|    |\n"
           "| N  |\n"
           "|____|\n");
  } else {
    printf("\033[34m");
    printf(" ____ \n"
           "|    |\n"
           "| D  |\n"
           "|____|\n");
  }
}

int main() {
  printf("State Index:\nPark = 00\nReverse = 01\nNeutral = 10\nDrive = 11\n\n[Input Them Without Space, For Example:\n0011 -> park state to drive state\n\n");
  int input;
  int A, B, C, D;
  int y1, y2;
  printf("Enter value for Current State and Input State: ");
  scanf("%4d", &input);
  A = input / 1000;
  B = (input / 100) % 10;
  C = (input / 10) % 10;
  D = input % 10;
  printf("\033c");
  compute_outputs(A, B, C, D, &y1, &y2);
  printf("\nCurrent State = %d%d | Input = %d%d \n\nOutput = %d%d\n\n", A, B, C, D, y1, y2);
  return 0;
}

// gcc -o main main.c
// ./main

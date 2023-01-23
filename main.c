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
  for (int A = 0; A <= 1; A++) {
    for (int B = 0; B <= 1; B++) {
      for (int C = 0; C <= 1; C++) {
        for (int D = 0; D <= 1; D++) {
          int y1, y2;
          printf("\033c");
          compute_outputs(A, B, C, D, &y1, &y2);
          printf("\nCurrent State = %d%d | Input = %d%d \n\nOutput = %d%d\n\n", A, B, C, D, y1, y2);
          sleep(1.8); 
          
          

        }
      }
    }
  }
  return 0;
}

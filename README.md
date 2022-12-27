# SciComp-FP-FSM-Harman-



The chosen system for this FSM is a Sequential Automatic Transmission, with states P, R, N, D.


Firstly, Here below is the diagram for the FSM of this Transmission:

![gvw9di0ndqlc5ovoku-removebg-preview](https://user-images.githubusercontent.com/114371673/209610805-6bc6ca8a-4b30-4991-a416-99ec4e75b8ce.jpg)



In this FSM diagram, it shows four states P, R, N, D. [Park, Reverse, Neutral, Drive]
In this automatic transmission FSM, the binary assignments are as below:

00: P

01: R

10: N

11: D

When state is in P, it has four possible outcomes if given an input, the outcomes after the input can be: Stay in P, Change to R, Change to N, Change to D.

When state is in R, it has three possible outcomes if given an input, the outcome after the input can be: Change to P, Stay in R, Change to N. The R state cannot go to D directly and will stay in R if given the input for D (11)

When State is in N, it has four possible outcomes if given an input, the outcomes after the input can be: Change to P, Change to R, Stay in N, Change to D.

When State in D, it has only two possible outcomes if given an input, the outcomes after the input can be: Change to N, Stay in D. D is not able to directly change states to R or P and will stay in D if given the inputs for R or P (01 or 00).







Here below is the State and Transition Table for the automatic transmission FSM:


![image](https://user-images.githubusercontent.com/114371673/209611610-684d008f-b80f-4914-aa4d-1cae6fe605bb.png)



In the above table: 

The first column represents the min terms, which ranges from m0 till m15, and is later used for the formats of the K-Map.

The second column represents the Current State of the FSM and are labelled as A B, so for instance if the a row in that column has 01, then 0 is labelled as A and 1 is labelled as B

The third column represents the Inputs, these inputs are labelled as C D. The labelling format for C D to it's binaries is similiar to that of the second column.

The fourth column represents the Next State. This column isn't labelled and it is there just to display what the next state would be after the current recieves input.

The fifth column represents the Output. This column is labelled as Y1 Y2, labelling is formatted the same way as the second and third column.



Now that the State and Transition Table is complete, the next step is to create the K-map. Since i have an output of two bits Y1 and Y2, i will create two different K-maps, one for Y1 and one more for Y2, and derive the combinatorial boolean equations from both of these K-maps.


Here below is the K-Map for Y1:


![image](https://user-images.githubusercontent.com/114371673/209612822-f9e3377a-0577-4e48-be76-72396e454dd6.png)


The derived combinatorial boolean equation for Y1 = B'C + CD' + AB


Here below is the K-Map for Y2:

![image](https://user-images.githubusercontent.com/114371673/209613106-5c916546-ee4d-4074-acbd-5dc82e2e6d5e.png)


The derived combinatorial boolean equation for Y2 = D + ABC'




After deriving both combinatorial boolean equation for Y1 and Y2, we can say that:

Output Y1 = B'C + CD' + AB


Output Y2 = D + ABC'



Now comes the final part of Implementing this on C. 


In the main.c (which can be found in this repo), it starts off with:

#include <stdio.h>
#include <unistd.h>

void compute_outputs(int A, int B, int C, int D, int *y1, int *y2) {
*y1 = !B & C | C & !D | A & B;
*y2 = D | A & B & !C;




The main implimentation of the Derived combinatorial boolean equation for Y1 and Y1 is done inside of that function called compute_outputs. This function stores A,B,C,D as integers and along with y1 y2 which are both pointers. After that, the pointer y1 is storing what is similiar to the derived combinatorial boolean expression from the K-Map of y1 which was done before. 

B'C + CD' + AB here  is expressed in C by !B & C | C & !D | A & B

D + ABC' here is expressed in C by D | A & B & !C

Everything done below from that point in the main.c are just visualization codes which helps showing the visualization in what the outputs are in each possible state and inputs, the terminal will show the current state with input and output in the same order as the state and transition table, thanks to the very long loop created in the int main(). The terminal will show a simple sort of ASCII art, where in the white texts will represent Park state, the red texts will represent Reverse state, the green texts will represent Neutral state, and finally the blue texts will represent the Drive state. (P,R,N,D). 


   

  









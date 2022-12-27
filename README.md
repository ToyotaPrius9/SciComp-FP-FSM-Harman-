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
When state is in R, it also has three possible outcomes if given an input, the outcome after the input can be: Change to P, Stay in R, Change to N. The R state cannot go to D directly and will stay in R if given the input for D (11)
When State is in N, it has four possible outcomes if given an input, the outcomes after the input can be: Change to P, Change to R, Stay in N, Change to D.
When State in D, it has only two possible outcomes if given an input, the outcomes after the input can be: Change to N, Stay in D. D is not able to directly change states to R or P and will stay in D if given the inputs for R or P (01 or 00).


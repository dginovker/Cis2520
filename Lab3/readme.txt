****************************************************
Daniel Ginovker, 0954042
Data Structures, 0106 - Lab 3
DATE, dcress01@mail.uoguelph.ca
****************************************************

************
Compilation
************
make - This line will compile main.c (not required to be marked for this lab, but will compile and execute if desired)
Output: bin/main.out

make test - This line will compile testMain.c (required for this lab)
Output: bin/testMain.out

***********************
Running the program(s)
***********************
In the bin/ folder, run ./testMain.out. No command line arguments required.

*****************
Known Limitations
*****************
None

*****************
Question 1: What are the benefits of testing with multiple data types?
Answer 1: The integer pointer data type is easier to start with as a programer and can be easier to debug when
errors are caught earlier on. It also provides more variety for testing which is crucial for a thouroughly
tested program. The more complex data type is useful for checking how good the program is at doing more complex
tasks properly.

Question 2: If we wanted to test the print functions, how might we change the signature to do that?
Answer 2: The print functions could instead return a string with the values that would otherwise be printed.
Those values can be compared against a string with the values we would otherwise be expecting.

Question 3: Does getFromFront() remove the first element?
Answer 3: No it does not. getFromFront() is purely a retrieval function and has no affect on the list. This can
be seen throughout the program when it's used in testMain.c
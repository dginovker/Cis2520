****************************************************
Daniel Ginovker, 0954042
Data Structures, 0106 - Assignment 2
October 22nd, 2017, dcress01@mail.uoguelph.ca
****************************************************

************
Compilation
************
Type "make" to compile the main program. "main.out" is generated and inserted into the /bin directory.
Type "make test" to compile the testing program. "testMain.out" is generated and inserted into the /bin directory.

***********************
Running the program(s)
***********************
 To run the main program, run main.out in the /bin directory.
 The first command line argument should be the file that has the patient data in it.
 It should be noted that a starvation algorithm has been implemented; the way it was interperated by the assignment
is that the patients at the end of the file would have gotten into the hospital "after" those who got in first. The
aging algorithm, as described here: http://www.geeksforgeeks.org/starvation-aging-operating-systems/ uses a simple
mechanism that decreases the priority (brings the node closer to the front) for the people who entered into the
hospital earlier, even if their condition isn't as severe.

 To run the test program, run testMain.out in the /bin directory. There are no additional parameters.
 It should also be noted that while the priority number is stored in the Node's data, it's also stored directly in the Node
and that's where it's used during insertSorted. The version in the Node is also affected by the aging algorithm, whereas the
one in the data is not.

*****************
Known Limitations
*****************
 If the priority number inserted from the file is less than 0 or greater than 10 the program doesn't process it correctly
(but the code doesn't crash either)
 If the file to be read in exceeds ~2.4 million lines the server boots you offline (who could have guessed?)

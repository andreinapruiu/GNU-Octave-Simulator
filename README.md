&copy; 2021-2022 Andrei Napruiu (napruiuandrei@gmail.com)

# Second PC Homework - Simpler GNU Octave simulator

> **Mentions before start:**
> + Main code is found inside ***my_octave.c*** file.
> + The actual pdf with all the requirements for this homework can be found [here](https://github.com/andreinapruiu/pdfs-PC/blob/main/Programare_2021___Tema_2.pdf).
> + The README file included in the repo is just so the checker gives 100 points on this homework.
> + After reading what each command does you can go on and [run the code](#how-to-run-the-code) or [check the problems](#how-to-run-the-checker).

# Contents:
1. [Short Description](#short-description)
2. [Commands](#commands)
3. [Example of running code](#example)
4. [How are the variables used in the program?](#how-are-the-variables-used-in-the-program)
3. [How to run the code?](#how-to-run-the-code)
4. [How to run the checker?]()
5. [Other sources](#sources-for-strassenaka-copyright)

# Short description
The program imitates the GNU Octave software by working with matrixes, same as MatLab. Having a set of commands predefined
and using dynamic allocation for every structure in the working
space, the program solves the problems sent by the user.

# Commands
Below is the list of every command (in some cases explained), its input and its output.

> Note: to execute a specific command, besides the input numbers, you need to type the specific letter.

## First command - L
**(loading of a matrix in memory)**

1. Input:
	- n, m = the number of lines and columns of a matrix ;
	- n x m numbers representing the elements of the matrix.
2. Process: it takes these numbers and for each L command the 
program dynamicly allocates a matrix in an array
of matrixes, also dynamicly allocated.
3. Output:
	- if everything worked just fine, nothing
	- else it will
show a specific message so that the user knows what
didn't work.

## Second command - D
**(showing the sizes of a matrix)**

1. Input:
	- index = self explanatory(the index of a matrix in
the array of matrixes)
2. Output: 
	+ the number of lines and columns of the matrix
at the given index
	+ a specific message if the index doesn't
correspond to a matrix in the array

## Third command - P
**(printing a matrix)**

1. Input:
	- index = self explanatory(the index of a matrix in
the array of matrixes)
2. Output:
	+ the matrix itself
	+ a specific message if the index doesn't
correspond to a matrix in the array

## Fourth command - C
**(resizing a matrix)**

1. Input:
	- index = self explanatory(the index of a matrix in
the array of matrixes)
	- n followed by n values = number of lines and the lines indexes
		after which the resizing is made
	- m followed by m values = same as before, but for columns
2. Process: the indexes of the lines and columns are combined
to get elements one by one and then they are put
in a matrix with the specific size. The matrix will 
then replace the original matrix from the array.
3. Output:
	- nothing if anything worked just fine
	- a specific message if the index doesn't
correspond to a matrix in the array
	- a specific message so that the user knows
what didn't work

## Fifth command - M
**(multiplying 2 matrixes)**

1. Input:
	- indexes = self explanatory(the index of 2 matrixes
in the array of matrixes)
2. Process: the 2 matrixes are creating another one, representing
their product. This product will be then stored at the
last postion of the array of matrixes
3. Output:
	- nothing if anything worked just fine
	- a specific message if the index doesn't
correspond to a matrix in the array
	- a specific message so that the user knows
what didn't work

## Sixth command - O
**(sorting everything)**

1. Input:
	- just the letter specifying the case
2. Process: all of the array of matrixes will be sorted by 
the sum of each matrix's elements, ascending order
3. Output:
	- nothing if anything worked just fine
	- a specific message so that the user knows
what didn't work

## Seventh command - T
**(transpose of a matrix)**

1. Input:
	- index = self explanatory(the index of a matrix in
the array of matrixes)
2. Process: the matrix coresponding to the index will be 
used to create its transpose. After that, the
transpose will overwrite the older matrix
3. Output:
	- nothing if anything worked just fine
	- a specific message if the index doesn't
correspond to a matrix in the array
	- a specific message so that the user knows
what didn't work

## Eighth command - F
**(freeing a matrix)**

1. Input:
	- index = self explanatory(the index of a matrix in
the array of matrixes)
2. Process: the matrix coresponding to the index will be 
eliminated from the array and also will be freed
3. Output:
	- nothing if anything worked just fine
	- a specific message if the index doesn't
correspond to a matrix in the array
	- a specific message so that the user knows
what didn't work

## Ninth command - Q
**(terminating the program/
	freeing everything)**

1. Input:
	- just the letter specifying the case
2. Process: the array of matrixes will be freed with each
matrix one by one
3. Output:
	- nothing if anything worked just fine
	- a specific message so that the user knows
what didn't work

## Tenth command - S
**(multiplying 2 matrixes using Strassen algorithm)**

1. It works like the M command, but with another algorithm

---
# Example

## Input

L 2 3<br>
4330 4243 5453 <br>
2432 4322 6785 <br>
L 3 4<br>
2312 2657 3292 3587 <br>
3273 3203 3493 9298 <br>
2193 2143 6576 6322 <br>
L 3 3 <br>
2422 4312 6577 <br>
6576 5644 4325 <br>
5435 6456 4576 <br>
P 2 <br>
P 1 <br>
O <br>
D 2 <br>
T 2 <br>
Z <br>
M 2 0 <br>
P 3 <br>
C 3 <br>
3 <br>
2 0 2 <br>
2 <br>
2 0 <br>
P 3 <br>
F 3 <br>
P 3 <br>
Q

## Output

2422 4312 6577 <br>
6576 5644 4325 <br>
5435 6456 4576 <br>
2312 2657 3292 3587 <br>
3273 3203 3493 9298 <br>
2193 2143 6576 6322 <br>
3 4 <br>
Unrecognized command <br>
4560 365 9365 <br>
8010 9593 5662 <br>
7111 835 3725 <br>
8555 3812 152 <br>
3725 7111 <br>
9365 4560 <br>
3725 7111 <br>
No matrix with the given index <br>

---

# How are the variables used in the program

**collection** = the array of matrixes in which the matrixes are stored one by one

**index** = the number of matrixes in the array

**lines** = the array that holds onto the line sizes of each matrix

**columns** = the array that holds onto the column sizes of each matrix

**nl** = number of lines(most of the time)

**nc** = number of columns(most of the time)

**aux** = temporary variable used for swapping

# How to run the code?
1. Download the files as shown in the repo;
2. Open a terminal and change the current directory with the one containing the code;
3. Run the following commands:
	- make
	- ./my_octave
	- the set of commands and numbers(data)

## Example
```bash
student@pc:~$ make
gcc -Wall -Wextra -std=c99   -c -o my_octave.o my_octave.c
gcc   my_octave.o   -o my_octave
student@pc:~$ ./my_octave 
L 2 2
1 2 3 4
L 2 2
5 6 7 8
M 0 1
P 2
19 22 
43 50 
Q
```

> Note: you can run the code using valgrind to keep track of memory leaks(they don't exist I can assure you)

For valgrind run:
```bash
student@pc:~$ make
gcc -Wall -Wextra -std=c99   -c -o my_octave.o my_octave.c
gcc   my_octave.o   -o my_octave
student@pc:~$ valgrind --leak-check=full -s ./my_octave 
L 2 2
1 2 3 4
L 2 2
5 6 7 8
M 0 1
P 2
19 22 
43 50 
Q
```

# How to run the checker?
1. Download the files as shown in the repo;
2. Open a terminal and change the current directory with the one containing the code;
3. Run the following command:

```bash
student@pc:~$ ./check
```

> You will be prompted with a lot of lines verifying a number of inputs for each command. All the inputs can be found in **tasks** folder.

> Note: if the command above doesn't work, you first need to use the following command that will install any other tool needed:
```bash
student@pc:~$ ./install.sh
```

If you want to verify the coding style(based on **Google's coding style**, run:
```bash
student@pc:~$ cs/cs.sh <file>
```

> It will check the coding style on the \<file\> in the tree and print a message inside the command line if it found something irregular.


# Sources for Strassen(aka Copyright):

https://medium.com/swlh/strassens-matrix-multiplication-algorithm-936f42c2b344
https://tinyurl.com/yc4w452n
https://www.youtube.com/watch?v=0oJyNmEbS4w
https://www.geeksforgeeks.org/easy-way-remember-strassens-matrix-equation/

---

***Thank you***

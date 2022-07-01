&copy; 2021-2022 Andrei Napruiu (napruiuandrei@gmail.com)

# First PC Homework - Functions and static structures(Arrays, Matrix)

> **Mentions before start:**
> + Main code is found inside ***my_octave.c*** file.
> + The actual pdf with all the requirements for this homework can be found [here](https://github.com/andreinapruiu/pdfs-PC/blob/main/Programare_2021___Tema_2.pdf).
> + The README file included in the repo is just so the checker gives 100 points on this homework.
> + After reading what each command does you can go on and [run the code](#how-to-run-the-code) or [check the problems](#how-to-run-the-checker).

# Contents:
1. [Short Description](#short-description)
1. [Problem 1](#on-the-fly-analysis)
2. [Problem 2](#natural-numbers-properties)
3. [Problem 3](#improving-scores)
4. [Problem 4](#nomogram-checker)

## Short description
This was a homework given during the **PC(Computer Programming)** course in my first year. As seen below, I had to solve 4 different problems of various difficulties. The problems were supposed to be an introduction to C programming language by using static structures, such as arrays and matrixes, or even simple functions to solve algorithmical questions. It was a simple and fun homework. Each of the 4 problems will be described below.


-------------------------------Short description-------------------------------

	The program imitates the GNU Octave software by working with
	matrixes, same as MatLab. Having a set of commands predefined
	and using dynamic allocation for every structure in the working
	  space, the program solves the problems sent by the user.

-----------------------------------Commands------------------------------------

			     ## First command - L ##
			 (loading of a matrix in memory)
			     
	     1. Input:|- n, m = the number of lines and columns of a matrix 
		      |- n x m numbers representing the elements of the matrix
	     2. Process: it takes these numbers and for each L command the 
	     		program dynamicly allocates a matrix in an array
	     		of matrixes, also dynamicly allocated
	     3. Output: if everything worked just fine, nothing. Else it will
	     		show a specific message so that the user knows what
	     		didn't work
	     	
			     ## Second command - D ##
			  (showing the sizes of a matrix)
			     
	     1. Input: index = self explanatory(the index of a matrix in
	     			the array of matrixes)
	     2. Output: a. the number of lines and columns of the matrix
	     		   at the given index
	     		b. a specific message if the index doesn't
	     		   correspond to a matrix in the array
	     		
			     ## Third command - P ##
			  	(printing a matrix)
			     
	     1. Input: index = self explanatory(the index of a matrix in
	     			the array of matrixes)
	     2. Output: a. the matrix itself
	     		b. a specific message if the index doesn't
	     		   correspond to a matrix in the array
	     		   
			     ## Fourth command - C ##
			  	(resizing a matrix)
			     
	     1. Input:|- index = self explanatory(the index of a matrix in
	     			the array of matrixes)
	     	      |- n and n values = number of lines and the lines indexes
	     	      		   after which the resizing is made
	     	      |- m and m values = same as before, but for columns
	     2. Process: the indexes of the lines and columns are combined
	     		to get elements one by one and then they are put
	     		in a matrix with the specific size. The matrix will 
	     		then replace the original matrix from the array.
	     3. Output: a. nothing if anything worked just fine
	     		b. a specific message if the index doesn't
	     		   correspond to a matrix in the array
	     		c. a specific message so that the user knows
	     		   what didn't work
	     		   
			     ## Fifth command - M ##
			     (multiplying 2 matrixes)
			     
	     1. Input: indexes = self explanatory(the index of 2 matrixes
	     			in the array of matrixes)
	     2. Process: the 2 matrixes are creating another one, representing
	     		their product. This product will be then stored at the
	     		last postion of the array of matrixes
	     3. Output: a. nothing if anything worked just fine
	     		b. a specific message if the index doesn't
	     		   correspond to a matrix in the array
	     		c. a specific message so that the user knows
	     		   what didn't work
	     		   
			     ## Sixth command - O ##
			      (sorting everything)
			     
	     1. Input: just the letter specifying the case
	     2. Process: all of the array of matrixes will be sorted by 
	     		 the sum of each matrix's elements, ascending order
	     3. Output: a. nothing if anything worked just fine
	     		b. a specific message so that the user knows
	     		   what didn't work
	     		   
			     ## Seventh command - T ##
			     (transpose of a matrix)
			     
	     1. Input: index = self explanatory(the index of a matrix in
	     			the array of matrixes)
	     2. Process: the matrix coresponding to the index will be 
	     		 used to create its transpose. After that, the
	     		 transpose will overwrite the older matrix
	     3. Output: a. nothing if anything worked just fine
	     		b. a specific message if the index doesn't
	     		   correspond to a matrix in the array
	     		c. a specific message so that the user knows
	     		   what didn't work
	     		   
			     ## Eighth command - F ##
			     	(freeing a matrix)
			     
	     1. Input: index = self explanatory(the index of a matrix in
	     			the array of matrixes)
	     2. Process: the matrix coresponding to the index will be 
	     		 eliminated from the array and also will be freed
	     3. Output: a. nothing if anything worked just fine
	     		b. a specific message if the index doesn't
	     		   correspond to a matrix in the array
	     		c. a specific message so that the user knows
	     		   what didn't work
	     		   
			     ## Ninth command - Q ##
			     (terminating the program/
			     	 freeing everything)
			     
	     1. Input: just the letter specifying the case
	     2. Process: the array of matrixes will be freed with each
	     		 matrix one by one
	     3. Output: a. nothing if anything worked just fine
	     		b. a specific message so that the user knows
	     		   what didn't work
	     		   
			     ## Tenth command - S ##
		(multiplying 2 matrixes using Strassen algorithm)
			     
	     1. It works like the M command, but with another algorithm


------------------How are the variables used in the program--------------------

collection = the array of matrixes in which the matrixes are stored one by one
index = the number of matrixes in the array
lines = the array that holds onto the line sizes of each matrix
columns = the array that holds onto the column sizes of each matrix
nl = number of lines(most of the time)
nc = number of columns(most of the time)
aux = temporary variable used for swapping

-----------------------Sources for Strassen(aka Copyright):--------------------

https://medium.com/swlh/strassens-matrix-multiplication-algorithm-936f42c2b344
https://tinyurl.com/yc4w452n
https://www.youtube.com/watch?v=0oJyNmEbS4w
https://www.geeksforgeeks.org/easy-way-remember-strassens-matrix-equation/

-------------------------------------------------------------------------------

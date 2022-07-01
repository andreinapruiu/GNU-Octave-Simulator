// Copyright Napruiu Andrei 312CAb 2021-2022
#include <stdio.h>
#include <stdlib.h>
#define MODULO 10007

// Function to free a matrix
void free_matrix(int **a, int nl)
{
	for (int i = 0; i < nl; i++)
		free(a[i]);

	free(a);
}

// Function to allocate a matrix and then return it to
// be stored in a variable
int **alloc_matrix(int nl, int nc)
{
	int **a;

	a = malloc(nl * sizeof(int *));
	if (!a)
		return NULL;

	for (int i = 0; i < nl; i++) {
		a[i] = malloc(nc * sizeof(int));
		if (!a[i]) {
			free_matrix(a, i);
			return NULL;
		}
	}

	return a;
}

// Function to read a matrix already allocated in memory
void read_matrix(int **a, int nl, int nc)
{
	for (int i = 0; i < nl; i++)
		for (int j = 0; j < nc; j++)
			scanf("%d", &a[i][j]);
}

// Function to print a matrix from the memory
void print_matrix(int n, int m, int **a)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

// Function that allocates memory for the array of matrixes and also
// for lines and columns arrays mentioned in main()
void solve_case_L(int ****collection, int **lines, int **columns, int *index)
{
	*lines = realloc(*lines, ((*index) + 1) * sizeof(int));
	*columns = realloc(*columns, ((*index) + 1) * sizeof(int));
	*collection = realloc(*collection, ((*index) + 1) * sizeof(int **));

	if (!(*lines) || !(*columns)) { // if the allocation couldn't be done
									// the program shows a special message
		printf("Gigel, something went wrong with the allocation\n");
		return;
	}

	int nl, nc;
	scanf("%d%d", &nl, &nc);
	(*collection)[*index] = alloc_matrix(nl, nc);

	if (!(*collection)[*index]) {
		printf("Gigel, something went wrong with the allocation\n");
	} else {
		read_matrix((*collection)[*index], nl, nc);
		(*lines)[*index] = nl;
		(*columns)[*index] = nc;
		(*index) = (*index) + 1;
	}
}

// Function that prints, for a specified matrix at a given index,
// the sizes(number of lines and number of columns)
void solve_case_D(int *lines, int *columns, int index)
{
	int nr = 0;
	scanf("%d", &nr);

	if (index <= nr || nr < 0) { // if the given index is greater than the max
							   // index used in the array of matrixes, it will
							   // show a message
		printf("No matrix with the given index\n");
	} else {
		printf("%d %d\n", lines[nr], columns[nr]);
	}
}

// Function that prints a matrix from the array of matrixes, at a given index
void solve_case_P(int ***collection, int *lines, int *columns, int index)
{
	int nr = 0;
	scanf("%d", &nr);

	if (index <= nr || nr < 0) { // same as the previous function
		printf("No matrix with the given index\n");
	} else {
		print_matrix(lines[nr], columns[nr], collection[nr]);
	}
}

// Function that resizes a matrix to a given number of lines and columns
int **redimension_matrix(int **a, int *lines, int nl_a,
						 int nl, int *columns, int nc)
{
	int **redimension = alloc_matrix(nl, nc);
	for (int i = 0; i < nl; i++)
		for (int j = 0; j < nc; j++)
			redimension[i][j] = a[lines[i]][columns[j]];

	free_matrix(a, nl_a);

	return redimension;
}

// Function that resizes a matrix to a given number of lines and columns
// and then replaces the original matrix with the resized one
void solve_case_C(int ****collection, int **lines, int **columns, int index)
{
	int nr = 0;
	scanf("%d", &nr);

	int nl, nc, *lines_array, *columns_array;

	scanf("%d", &nl);
	lines_array = malloc(nl * sizeof(int));
	if (!lines_array) {
		printf("Gigel, something went wrong with the allocation\n");
		free(lines_array);
		return;
	}
	for (int i = 0; i < nl; i++)
		scanf("%d", &lines_array[i]);

	scanf("%d", &nc);
	columns_array = malloc(nc * sizeof(int));
	if (!columns_array) {
		printf("Gigel, something went wrong with the allocation\n");
		free(lines_array);
		free(columns_array);
		return;
	}

	for (int i = 0; i < nc; i++)
		scanf("%d", &columns_array[i]);

	if (index <= nr || nr < 0) { // same with the message
		printf("No matrix with the given index\n");
		free(lines_array);
		free(columns_array);
		return;
	}

	(*collection)[nr] = redimension_matrix((*collection)[nr],
											lines_array, (*lines)[nr],
											nl, columns_array, nc);

	(*lines)[nr] = nl;
	(*columns)[nr] = nc;

	free(lines_array);
	free(columns_array);
}

// Function that returns a matrix based on the multiplication of
// 2 given matrixes
int **multiply_matrixes(int **a, int nl_a, int nc_a,
						int **b, int nc_b)
{
	int **multiplication = alloc_matrix(nl_a, nc_b);
	int p; // variable for the sum of products

	for (int i = 0; i < nl_a; i++)
		for (int j = 0; j < nc_b; j++) {
			p = 0;
			for (int k = 0; k < nc_a; k++) {
				p = (p + a[i][k] * b[k][j]) % MODULO;

				p %= MODULO;
			}

			if (p < 0)
				p += MODULO;

			multiplication[i][j] = p % MODULO;
		}

	return multiplication;
}

// Function that creates a multiplication of 2 given matrixes from the
// array of matrixes and then stores the result in the array(last position)
void solve_case_M(int ****collection, int **lines, int **columns, int *index)
{
	*lines = realloc(*lines, ((*index) + 1) * sizeof(int));
	*columns = realloc(*columns, ((*index) + 1) * sizeof(int));
	*collection = realloc(*collection, ((*index) + 1) * sizeof(int **));

	if (!(*lines) || !(*columns)) { // if the allocation couldn't be done
									// the program shows a special message
		printf("Gigel, something went wrong with the allocation\n");
		return;
	}

	int index1, index2;
	scanf("%d%d", &index1, &index2);

	if ((index1 >= *index || index1 < 0) || (index2 >= *index || index2 < 0)) {
		printf("No matrix with the given index\n");
		return;
	}

	if ((*columns)[index1] != (*lines)[index2]) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}
	(*collection)[*index] =
	multiply_matrixes((*collection)[index1], (*lines)[index1],
					  (*columns)[index1], (*collection)[index2],
					  (*columns)[index2]);
	(*lines)[*index] = (*lines)[index1];
	(*columns)[*index] = (*columns)[index2];
	(*index) = (*index) + 1;
}

// Function to swap to integers
void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

// Function that returns the sum of all the elements in a matrix
// with the specified modulo
int sum_matrix(int **a, int nl, int nc)
{
	int s = 0;
	for (int i = 0; i < nl; i++)
		for (int j = 0; j < nc; j++) {
			s = (s + a[i][j]) % MODULO;

			if (s < 0)
				s += MODULO;
		}

	return s;
}

// Function that sorts all the matrixes in the array by their elements sum
void solve_case_O(int ****collection, int **lines, int **columns, int index)
{
	for (int i = 0; i < index - 1; i++) {
		for (int j = i + 1; j < index; j++) {
			if (sum_matrix((*collection)[i], (*lines)[i], (*columns)[i]) >
				sum_matrix((*collection)[j], (*lines)[j], (*columns)[j])) {
				int **aux;
				aux = (*collection)[i];
				(*collection)[i] = (*collection)[j];
				(*collection)[j] = aux;

				swap(&(*lines)[i], &(*lines)[j]);
				swap(&(*columns)[i], &(*columns)[j]);
			}
		}
	}
}

// Function that returns the transpose of a given matrix
// and frees the previous matrix given as a parameter
int **transpose_matrix(int **a, int nl, int nc)
{
	int **transpose = alloc_matrix(nc, nl);

	for (int i = 0; i < nl; i++)
		for (int j = 0; j < nc; j++)
			transpose[j][i] = a[i][j];

	free_matrix(a, nl);

	return transpose;
}

// Function that replaces a matrix at a given index, from the array of matrixes
// with its transpose
void solve_case_T(int ****collection, int **lines, int **columns, int index)
{
	int nr = 0;
	scanf("%d", &nr);

	if (index <= nr || nr < 0) { // same with the message
		printf("No matrix with the given index\n");
	} else {
		(*collection)[nr] = transpose_matrix((*collection)[nr],
											 (*lines)[nr], (*columns)[nr]);

		int aux;

		aux = (*lines)[nr];
		(*lines)[nr] = (*columns)[nr];
		(*columns)[nr] = aux;
	}
}

// Function that frees a matrix from a given index in the array of matrixes
// and also reallocates the memory so that the array of matrixes has the new
// number of matrixes(index decreases so memory for array needs to decrease)
void solve_case_F(int ****collection, int **lines, int **columns, int *index)
{
	int nr = 0;
	scanf("%d", &nr);

	if (*index <= nr || nr < 0) { // same with the message
		printf("No matrix with the given index\n");
	} else {
		free_matrix((*collection)[nr], (*lines)[nr]);

		for (int i = nr; i < *index - 1; i++) {
			(*collection)[i] = (*collection)[i + 1];
			(*lines)[i] = (*lines)[i + 1];
			(*columns)[i] = (*columns)[i + 1];
		}

		(*index)--;

		*lines = realloc(*lines, ((*index)) * sizeof(int));
		*columns = realloc(*columns, ((*index)) * sizeof(int));
		*collection = realloc(*collection, ((*index)) * sizeof(int **));
	}
}

// Function that frees everything allocated so that there won't be
// any problems
void special_case_Q(int ****collection, int **lines, int **columns, int index)
{
	for (int i = 0; i < index; i++)
		free_matrix((*collection)[i], (*lines)[i]);
	free((*collection));
	free((*lines));
	free((*columns));
}

// Function that returns the sum of 2 matrixes
int **add(int **a, int **b, int n)
{
	int **sum = alloc_matrix(n, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum[i][j] = (a[i][j] + b[i][j]) % MODULO;

	return sum;
}

// Function that returns the difference of 2 matrixes
int **substract(int **a, int **b, int n)
{
	int **dif = alloc_matrix(n, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dif[i][j] = (a[i][j] - b[i][j]) % MODULO;

	return dif;
}

// The actual Strassen algorithm
int **strassen_multiply(int **a, int **b, int n)
{
	if (n == 1) {
		int **result = alloc_matrix(1, 1);
		result[0][0] = a[0][0] * b[0][0];
		return result;
	}

	int **result = alloc_matrix(n, n);
	int k = n / 2;
	// quarters of the matrixes
	int **QA11 = alloc_matrix(k, k), **QA12 = alloc_matrix(k, k);
	int **QA21 = alloc_matrix(k, k), **QA22 = alloc_matrix(k, k);
	int **QB11 = alloc_matrix(k, k), **QB12 = alloc_matrix(k, k);
	int **QB21 = alloc_matrix(k, k), **QB22 = alloc_matrix(k, k);

	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			QA11[i][j] = a[i][j];
			QA12[i][j] = a[i][k + j];
			QA21[i][j] = a[k + i][j];
			QA22[i][j] = a[k + i][k + j];
			QB11[i][j] = b[i][j];
			QB12[i][j] = b[i][k + j];
			QB21[i][j] = b[k + i][j];
			QB22[i][j] = b[k + i][k + j];
		}

	int **S11 = substract(QB12, QB22, k), **A11 = add(QA11, QA12, k);
	int **A12 = add(QA21, QA22, k), **S12 = substract(QB21, QB11, k);
	int **A13 = add(QA11, QA22, k), **A14 = add(QB11, QB22, k);
	int **S13 = substract(QA12, QA22, k), **A15 = add(QB21, QB22, k);
	int **S14 = substract(QA11, QA21, k), **A16 = add(QB11, QB12, k);

	int **P1 = strassen_multiply(QA11, S11, k);
	int **P2 = strassen_multiply(A11, QB22, k);
	int **P3 = strassen_multiply(A12, QB11, k);
	int **P4 = strassen_multiply(QA22, S12, k);
	int **P5 = strassen_multiply(A13, A14, k);
	int **P6 = strassen_multiply(S13, A15, k);
	int **P7 = strassen_multiply(S14, A16, k);

	free_matrix(QA11, k); free_matrix(QA12, k); free_matrix(QA21, k);
	free_matrix(QA22, k); free_matrix(QB11, k); free_matrix(QB12, k);
	free_matrix(QB21, k); free_matrix(QB22, k); free_matrix(S11, k);
	free_matrix(A11, k); free_matrix(A12, k); free_matrix(S12, k);
	free_matrix(A13, k); free_matrix(A14, k); free_matrix(S13, k);
	free_matrix(A15, k); free_matrix(S14, k); free_matrix(A16, k);

	int **A21 = add(P5, P4, k), **A22 = add(P5, P1, k);
	int **A23 = add(A21, P6, k), **S21 = substract(A22, P3, k);
	int **C11 = substract(A23, P2, k), **C12 = add(P1, P2, k);
	int **C21 = add(P3, P4, k), **C22 = substract(S21, P7, k);

	free_matrix(A21, k); free_matrix(A22, k);
	free_matrix(A23, k); free_matrix(S21, k);

	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			result[i][j] = C11[i][j] % MODULO;
			result[i][k + j] = C12[i][j] % MODULO;
			result[k + i][j] = C21[i][j] % MODULO;
			result[k + i][k + j] = C22[i][j] % MODULO;

			if (result[i][j] < 0)
				result[i][j] += MODULO;
			if (result[i][k + j] < 0)
				result[i][k + j] += MODULO;
			if (result[k + i][j] < 0)
				result[k + i][j] += MODULO;
			if (result[k + i][k + j] < 0)
				result[k + i][k + j] += MODULO;
		}

	free_matrix(C11, k); free_matrix(C12, k); free_matrix(C21, k);
	free_matrix(C22, k); free_matrix(P1, k); free_matrix(P2, k);
	free_matrix(P3, k); free_matrix(P4, k); free_matrix(P5, k);
	free_matrix(P6, k); free_matrix(P7, k);
	return result;
}

// Function that multiplies 2 matrixes at given indexes using
// Strassen's algorithm
void special_case_S(int ****collection, int **lines, int **columns, int *index)
{
	*lines = realloc(*lines, ((*index) + 1) * sizeof(int));
	*columns = realloc(*columns, ((*index) + 1) * sizeof(int));
	*collection = realloc(*collection, ((*index) + 1) * sizeof(int **));

	if (!(*lines) || !(*columns)) { // if the allocation couldn't be done
									// the program shows a special message
		printf("Gigel, something went wrong with the allocation\n");
		return;
	}

	int index1, index2;
	scanf("%d%d", &index1, &index2);

	if ((index1 >= *index || index1 < 0) || (index2 >= *index || index2 < 0)) {
		printf("No matrix with the given index\n");
		return;
	}

	if ((*columns)[index1] != (*lines)[index2]) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}

	int n = (*lines)[index1];
	(*collection)[*index] =
	strassen_multiply((*collection)[index1], (*collection)[index2], n);
	(*lines)[*index] = (*lines)[index1];
	(*columns)[*index] = (*columns)[index2];
	(*index) = (*index) + 1;
}

int main(void)
{
	int ***collection = malloc(1);
	int *lines = malloc(1), *columns = malloc(1), index = 0;
	char option = 'A';

	while (option != 'Q') {
		scanf("%c", &option);

		switch (option) {
		case 'L':
			solve_case_L(&collection, &lines, &columns, &index);
			break;
		case 'D':
			solve_case_D(lines, columns, index);
			break;
		case 'P':
			solve_case_P(collection, lines, columns, index);
			break;
		case 'C':
			solve_case_C(&collection, &lines, &columns, index);
			break;
		case 'M':
			solve_case_M(&collection, &lines, &columns, &index);
			break;
		case 'O':
			solve_case_O(&collection, &lines, &columns, index);
			break;
		case 'T':
			solve_case_T(&collection, &lines, &columns, index);
			break;
		case 'F':
			solve_case_F(&collection, &lines, &columns, &index);
			break;
		case 'Q':
			special_case_Q(&collection, &lines, &columns, index);
			break;
		case 'S':
			special_case_S(&collection, &lines, &columns, &index);
			break;
		case '\n': // special case because the scanf function reads a random
			break; // endline character sometimes
		default:
			printf("Unrecognized command\n");
			break;
		}
	}
	return 0;
}

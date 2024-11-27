/***
 * Flat Matrix Multiplication Function
 * 
 * This function performs a matrix multiplication operation on two 2D matrices represented as flat (1D) matrices.
 *
 * Written in C
 *
 * 11/25/2024
 *
 * Musa Jalis
 *
 ***/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int** matrix_generator(int width, int height) {
	int size = width * height;
	int **arr = (int **) malloc(height * sizeof(int *));
	if (arr == NULL) {
		return 0;
	}
	for (int i = 0; i < height; i++) {
		arr[i] = (int *) malloc(width * sizeof(int));
		if (arr[i] == NULL) {
			return 0;
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[i][j] = 1;
		}
	}
	return arr;
}

int** flat_matrix_multiplication(int** mat1, int** mat2, int mat1_width, int mat1_height, int mat2_width, int mat2_height) {
	if (mat1_width != mat2_height) {
		return 0;
	}
	
	int** result = matrix_generator(mat1_height, mat2_width);
	int size = mat1_height * mat2_width;

	for (int i = 0; i < mat1_height; i++) {
		for (int j = 0; j < mat2_width; j++) {
			for (int k = 0; k < mat1_width; k++) {
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	return result;
}

void dealloc_matrix(int** matrix, int height) {
	for (int i = 0; i < height; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

int main() {
	clock_t time;
	time = clock();
	int mat1_width = 4;
	int mat1_height = 2;
	int mat2_width = 5;
	int mat2_height = 4;
	
	int** mat1 = matrix_generator(mat1_width, mat1_height);
	int** mat2 = matrix_generator(mat2_width, mat2_height);
	int** result = flat_matrix_multiplication(mat1, mat2, mat1_width, mat1_height, mat2_width, mat2_height);
	printf("Resultant matrix memory address: %p\n", result);

	dealloc_matrix(mat1, mat1_height);
	dealloc_matrix(mat2, mat2_height);
	dealloc_matrix(result, mat1_height);
	
	time = clock() - time;
	double time_elapsed = ((double) time)/CLOCKS_PER_SEC;
	printf("TIME ELAPSED: %f\n", time_elapsed);
	return 0;
}

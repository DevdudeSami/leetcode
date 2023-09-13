#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    // The nth row becomes the nth column reversed

    // First transpose
    for(int row = 0; row < matrixSize; row++) {
        for(int col = 0; col < matrixColSize[row]; col++) {
            if(col <= row) continue; // skip if below leading diagonal
            int tmp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = tmp;
        }
    }

    // Reverse the columns
    for(int row = 0; row < matrixSize; row++) {
        for(int col = 0; col < matrixColSize[row]/2; col++) {
            int tmp = matrix[row][col];
            matrix[row][col] = matrix[row][matrixColSize[row]-1-col];
            matrix[row][matrixColSize[row]-1-col] = tmp;
        }
    }
}

int main() {
		int matrixSize = 3;
		int matrixColSize[] = {3, 3, 3};
		int **matrix = malloc(sizeof(int*) * matrixSize);
		for(int i = 0; i < matrixSize; i++) {
			matrix[i] = malloc(sizeof(int) * matrixColSize[i]);
		}

		int count = 1;
		for(int row = 0; row < matrixSize; row++) {
				for(int col = 0; col < matrixColSize[row]; col++) {
						matrix[row][col] = count++;
				}
		}

    rotate(matrix, matrixSize, matrixColSize);

    for(int row = 0; row < matrixSize; row++) {
        for(int col = 0; col < matrixColSize[row]; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

		for(int i = 0; i < matrixSize; i++) {
			free(matrix[i]);
		}
		free(matrix);

		return 0;
}
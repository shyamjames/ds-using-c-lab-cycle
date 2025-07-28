/*
10.	Write a program to find the transpose of a matrix
*/

#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[][MAX], int rows, int cols) {
    printf("Enter elements (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
}

void transposeMatrix(int matrix[][MAX], int transpose[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            transpose[j][i] = matrix[i][j];
}

void displayMatrix(int matrix[][MAX], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int matrix[MAX][MAX], transpose[MAX][MAX];
    int rows, cols;

    do {
        printf("Enter number of rows (max %d): ", MAX);
        scanf("%d", &rows);
        printf("Enter number of columns (max %d): ", MAX);
        scanf("%d", &cols);
        if (rows < 1 || rows > MAX || cols < 1 || cols > MAX)
            printf("Invalid size! Please enter again.\n");
    } while (rows < 1 || rows > MAX || cols < 1 || cols > MAX);

    inputMatrix(matrix, rows, cols);

    printf("Original Matrix:\n");
    displayMatrix(matrix, rows, cols);

    transposeMatrix(matrix, transpose, rows, cols);

    printf("Transpose Matrix:\n");
    displayMatrix(transpose, cols, rows);

    return 0;
}

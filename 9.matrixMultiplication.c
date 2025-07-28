/*
9.	Write a program to perform multiplication of two matrix
*/

#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[][MAX], int rows, int cols) {
    printf("Enter elements (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiplyMatrices(int a[][MAX], int b[][MAX], int result[][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;  // Initialize the result cell
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][MAX], int rows, int cols) {
    printf("Resulting matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    // Input dimensions of first matrix
    do {
        printf("Enter number of rows for first matrix (max %d): ", MAX);
        scanf("%d", &rowsA);
        printf("Enter number of columns for first matrix (max %d): ", MAX);
        scanf("%d", &colsA);
        if (rowsA < 1 || rowsA > MAX || colsA < 1 || colsA > MAX)
            printf("Invalid size! Please enter again.\n");
    } while (rowsA < 1 || rowsA > MAX || colsA < 1 || colsA > MAX);

    // Input dimensions of second matrix
    do {
        printf("Enter number of rows for second matrix (max %d): ", MAX);
        scanf("%d", &rowsB);
        printf("Enter number of columns for second matrix (max %d): ", MAX);
        scanf("%d", &colsB);
        if (rowsB < 1 || rowsB > MAX || colsB < 1 || colsB > MAX)
            printf("Invalid size! Please enter again.\n");
        else if (colsA != rowsB)
            printf("Number of columns of first matrix must equal number of rows of second matrix. Please enter again.\n");
    } while (rowsB < 1 || rowsB > MAX || colsB < 1 || colsB > MAX || colsA != rowsB);

    printf("Enter elements for first matrix:\n");
    inputMatrix(a, rowsA, colsA);

    printf("Enter elements for second matrix:\n");
    inputMatrix(b, rowsB, colsB);

    multiplyMatrices(a, b, result, rowsA, colsA, colsB);

    displayMatrix(result, rowsA, colsB);

    return 0;
}

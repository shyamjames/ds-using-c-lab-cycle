/*
8.	Write a program to Perform the addition of two matrix and Subtraction of one matrix from another
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

void addMatrices(int a[][MAX], int b[][MAX], int result[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subtractMatrices(int a[][MAX], int b[][MAX], int result[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] - b[i][j];
}

void displayMatrix(int matrix[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int sum[MAX][MAX], diff[MAX][MAX];
    int rows, cols;

    // Input the size of matrices
    do {
        printf("Enter number of rows (max %d): ", MAX);
        scanf("%d", &rows);
        printf("Enter number of columns (max %d): ", MAX);
        scanf("%d", &cols);

        if (rows < 1 || rows > MAX || cols < 1 || cols > MAX)
            printf("Invalid size. Please enter again.\n");
    } while (rows < 1 || rows > MAX || cols < 1 || cols > MAX);

    // Input matrices
    printf("Enter elements for first matrix:\n");
    inputMatrix(a, rows, cols);

    printf("Enter elements for second matrix:\n");
    inputMatrix(b, rows, cols);

    // Perform addition and subtraction
    addMatrices(a, b, sum, rows, cols);
    subtractMatrices(a, b, diff, rows, cols);

    printf("\nSum of the two matrices:\n");
    displayMatrix(sum, rows, cols);

    printf("\nDifference of the two matrices (First - Second):\n");
    displayMatrix(diff, rows, cols);

    return 0;
}

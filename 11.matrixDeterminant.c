/*
11.	Write a program to find the Determinant of a matrix (2x2 and 3x3)
*/

#include <stdio.h>

void readMatrix(int mat[10][10], int rows, int columns) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("The matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void determinant2x2(int b[10][10]) {
    int det1;
    det1 = b[0][0]*b[1][1] - b[0][1]*b[1][0];
    printf("Determinant of the 2 X 2 matrix is: %d\n", det1);
}

void determinant3x3(int b[10][10]) {
    int det2;
    det2 = b[0][0]*(b[1][1]*b[2][2] - b[1][2]*b[2][1]) -
           b[0][1]*(b[1][0]*b[2][2] - b[1][2]*b[2][0]) +
           b[0][2]*(b[1][0]*b[2][1] - b[1][1]*b[2][0]);
    printf("Determinant of the 3 X 3 matrix is: %d\n", det2);
}

int main() {
    int a[10][10];
    int row1, col1;

    printf("Enter number of rows (max 10): ");
    scanf("%d", &row1);

    printf("Enter number of columns (max 10): ");
    scanf("%d", &col1);

    if (row1 < 1 || row1 > 10 || col1 < 1 || col1 > 10) {
        printf("Invalid matrix size. Must be between 1 and 10.\n");
        return 1;
    }

    printf("Enter elements:\n");
    readMatrix(a, row1, col1);

    if (row1 == col1) {
        if (row1 == 2) {
            determinant2x2(a);
        } else if (row1 == 3) {
            determinant3x3(a);
        } else {
            printf("Determinant calculation for %dx%d is not implemented.\n", row1, col1);
        }
    } else {
        printf("The matrix is not a square matrix so determinant cannot be found.\n");
    }

    return 0;
}
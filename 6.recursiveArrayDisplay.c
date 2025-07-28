/*
6.	Display the array elements in the same order using a recursive function 
*/

#include <stdio.h>
#define MAX_SIZE 10

// Recursive function to print array elements in order
void displayRecursive(int a[], int index, int n) {
    if (index == n) 
        return;
    printf("%d\t", a[index]);
    displayRecursive(a, index + 1, n);  // Recursive call with next index
}

int main() {
    int a[MAX_SIZE], n, i;

    do {
        printf("Enter the size of the array (1 to %d): ", MAX_SIZE);
        scanf("%d", &n);
        if (n < 1 || n > MAX_SIZE)
            printf("Invalid size! Try again.\n");
    } while (n < 1 || n > MAX_SIZE);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Array elements (displayed recursively):\n");
    displayRecursive(a, 0, n);
    printf("\n");

    return 0;
}

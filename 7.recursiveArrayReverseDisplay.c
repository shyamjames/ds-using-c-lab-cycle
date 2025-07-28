/*
    7.	Display array elements in reverse order using a recursive function.
*/

#include <stdio.h>
#define MAX_SIZE 10

// Recursive function to display array elements in reverse order
void displayReverseRecursive(int a[], int index) {
    if (index < 0)  
        return;
    printf("%d\t", a[index]);
    displayReverseRecursive(a, index - 1);  
}

int main() {
    int a[MAX_SIZE], n, i;

    do {
        printf("Enter the size of the array (1 to %d): ", MAX_SIZE);
        scanf("%d", &n);
        if (n < 1 || n > MAX_SIZE)
            printf("Invalid size! Try again.\n");
    } while (n < 1 || n > MAX_SIZE);

    // Read elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Array elements in reverse order (displayed recursively):\n");
    displayReverseRecursive(a, n - 1);
    printf("\n");

    return 0;
}
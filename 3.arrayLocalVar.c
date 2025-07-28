/*
Menu driven program to insert, search, delete and sort elements in an array using functions
(use only local variables)
*/

#include <stdio.h>
#define MAX_SIZE 10

void readArray(int a[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int insert(int a[], int n) {
    int val, pos, i;
    if (n >= MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return n;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &val);
    printf("Enter position to insert at (1 to %d): ", n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return n;
    }
    for (i = n - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }
    a[pos - 1] = val;
    printf("Array after insertion:\n");
    for (i = 0; i <= n; i++)
        printf("%d\t", a[i]);
    printf("\n");
    return n + 1;
}

void search(int a[], int n) {
    int ele, flg = 0;
    printf("Enter element to search: ");
    scanf("%d", &ele);
    for (int i = 0; i < n; i++) {
        if (a[i] == ele) {
            printf("Element %d found at position %d.\n", ele, i + 1);
            flg = 1;
            break;
        }
    }
    if (!flg)
        printf("Element %d not found in the array.\n", ele);
}

int deleteElement(int a[], int n) {
    int pos, i;
    if (n == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return n;
    }
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return n;
    }
    printf("Deleting element %d at position %d.\n", a[pos - 1], pos);
    for (i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    printf("Array after deletion:\n");
    for (i = 0; i < n - 1; i++)
        printf("%d\t", a[i]);
    printf("\n");
    return n - 1;
}

void sortArray(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Array sorted.\n");
}

void display(int a[], int n) {
    if (n == 0)
        printf("Array is empty.\n");
    else {
        printf("Array elements:\n");
        for (int i = 0; i < n; i++)
            printf("%d\t", a[i]);
        printf("\n");
    }
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Sort the array\n");
    printf("2. Insert an element\n");
    printf("3. Search for an element\n");
    printf("4. Delete an element\n");
    printf("5. Display the array\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void processArray(int a[], int n) {
    int choice;
    int size = n;  // local copy of size that can change inside this function

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sortArray(a, size);
                display(a, size);
                break;
            case 2:
                size = insert(a, size);
                break;
            case 3:
                search(a, size);
                break;
            case 4:
                size = deleteElement(a, size);
                break;
            case 5:
                display(a, size);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter between 1-6.\n");
        }
    } while (choice != 6);
}

int main() {
    int a[MAX_SIZE], n;

    do {
        printf("Enter the size of the array (1 to %d): ", MAX_SIZE);
        scanf("%d", &n);
        if (n < 1 || n > MAX_SIZE)
            printf("Invalid size! Try again.\n");
    } while (n < 1 || n > MAX_SIZE);

    readArray(a, n);
    processArray(a, n);

    return 0;
}
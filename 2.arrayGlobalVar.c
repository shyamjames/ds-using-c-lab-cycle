// menu-driven program to insert, search, delete and sort elements in an array using functions (use global variables) 
#include <stdio.h>

int a[10], i, j, n, temp;
int pos, val;
int ele, flg = 0;

void read() {
    printf("Enter the size of the array (max 10): ");
    scanf("%d", &n);

    if (n > 10 || n <= 0) {
        printf("Invalid size! Please enter size between 1 and 10.\n");
        read();
        return;
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("The current array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void insert() {
    if (n >= 10) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    printf("Enter the element you want to insert: ");
    scanf("%d", &val);

    printf("Enter the position of the new element (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Please try again.\n");
        return;
    }

    for (i = n - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }

    a[pos - 1] = val;
    n++;

    printf("Array after insertion is: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void delete() {
    if (n == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter the position of the element to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position! Please try again.\n");
        return;
    }

    printf("Element %d at position %d deleted.\n", a[pos - 1], pos);

    for (i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;

    printf("Array after deletion is: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void search() {
    flg = 0;  // reset flag
    printf("Enter the element you want to search for: ");
    scanf("%d", &ele);

    for (i = 0; i < n; i++) {
        if (a[i] == ele) {
            printf("The element %d is found at position %d.\n", ele, i + 1);
            flg = 1;
            break;
        }
    }
    if (flg == 0) {
        printf("The element %d is not in the array.\n", ele);
    }
}

void sort() {
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void display() {
    printf("The array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    read();

    do {
        printf("\nMenu:\n");
        printf("1. Sort the array\n");
        printf("2. Insert an element\n");
        printf("3. Search for an element\n");
        printf("4. Delete an element\n");    // Added delete menu
        printf("5. Display the array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            sort();
            printf("Array after sorting:\n");
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            search();
            break;
        case 4:
            delete();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exited\n");
        break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

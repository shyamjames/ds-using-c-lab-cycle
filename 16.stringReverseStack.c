/*
16.	Reverse a string using Stack
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char str[MAX];
    char stack[MAX];
    int top = -1;
    int i, len;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    // Push characters onto stack
    for (i = 0; i < len; i++) {
        stack[++top] = str[i];
    }

    printf("Reversed string: ");
    // Pop characters from stack to display reversed string
    while (top >= 0) {
        putchar(stack[top--]);
    }
    printf("\n");

    return 0;
}

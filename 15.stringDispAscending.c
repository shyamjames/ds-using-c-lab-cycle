#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

int main() {
    int n, i, j;
    char strings[MAX_STRINGS][MAX_LENGTH];
    char temp[MAX_LENGTH];

    printf("Enter the number of strings (max %d): ", MAX_STRINGS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_STRINGS) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    getchar();

    // Read strings
    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        fgets(strings[i], MAX_LENGTH, stdin);

        // Remove trailing newline if present
        size_t len = strlen(strings[i]);
        if (len > 0 && strings[i][len - 1] == '\n') {
            strings[i][len - 1] = '\0';
        }
    }

    // Sort strings in ascending order using simple bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                // Swap strings[j] and strings[j+1]
                strcpy(temp, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], temp);
            }
        }
    }

    printf("\nStrings in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}

/*
Sort the array elements in ascending order(minimum 3 functions: read display and sort)
*/

#include <stdio.h>

int a[5];

void read(){
    printf("Enter the elements of the array:\n");
    int i;
    for(i=0;i<5;i++){
        printf("a[%d]= ",i);
        scanf("%d",&a[i]);
    }
}

void disp(){
    int i;
    for(i=0;i<5;i++){
        printf("%d\t",a[i]);
    }
}

void arraySort(){
    int temp,i,j;
    for (i = 0; i < 5; ++i) {
    for (j = i + 1; j < 5; ++j) {
        if (a[i] > a[j]) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}
printf("\nSorted Array:\n");
disp();
}

int main(){
    read();
    printf("Unsorted Array:\n");
    disp();
    arraySort();

    return 0;
}
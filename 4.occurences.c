#include <stdio.h>

void occurences(int a[],int n){
    int occ = 0;
    printf("\nOccurences for %d: ",n);
    for(int i=0;i<10;i++){
        if(a[i]==n){
            occ++;
            printf("a[%d]\t",i);
        }
    }
}

int main(){
    int size;
    printf("Enter the size of array:\n");
    scanf("%d",&size);
    int a[size];
    printf("Enter the elements of the array:");
    int i;
    for(i=0;i<size;i++){
        printf("a[%d]= ",i);
        scanf("%d",&a[i]);
    }

    printf("Enter the element to search for occurences:\n");
    int k;
    scanf("%d",&k);
    occurences(a,k);
    return 0;
}
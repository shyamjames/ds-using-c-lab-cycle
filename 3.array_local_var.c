#include <stdio.h>
#define MAX 10

//insertion
void insert(int a[]){
    int index,value;
    printf("Enter the index to insert: \n");
    scanf("%d",&index);
    printf("Enter the value to insert: \n");
    scanf("%d",&value);
    a[index] = value;
}

void search(int a[]){
    int n,i;
    printf("Enter the element to search: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(a[i]==n){
            printf("%d is in positoin a[%d].",n,i);
        }
    }
}

void delete(int n){
    int del = n;
    int ind;
    printf("Enter the index of the element to delete: ");
    scanf("%d",&ind);
    
}


int main(){
    int a[MAX];
    return 0;
}
#include<stdio.h>

int push(int n, int a[], int top){
    if(top+1==5){
        printf("Error: array is full!\n");
    }else{
        top++;
        a[top]=n;
    }
    return top;
}

int pop(int a[], int top){
    if(top == -1){
        printf("Error: Array is empty!\n");
    }else{
        printf("\n%d",a[top]);
        top--;
    }
    return top;
}

int menu(){
    int ch;
    printf("\nPUSH-1\nPOP-2\nPEEK-3\nEXIT-4\nEnter your choice:\n");
    scanf("%d",&ch);
    return ch;
}

void peek(int a[], int top){
    if(top == -1){
        printf("Error: Stack is empty!\n");
    } else {
        printf("\nTop: %d", a[top]);
    }
}

void processArray(int a[], int top){
    int ch, val;
    for(ch=menu();ch!=4;ch=menu()){
        switch(ch){
            case 1:
                printf("Enter the value to insert:\n");
                scanf("%d",&val);
                top = push(val,a,top);
                break;
            case 2:
                top = pop(a,top);
                break;
            case 3:
                peek(a,top);
                break;
            default:
                printf("Error wrong choice.");
                break;
        }
    }
}

int main(){
    int top=-1;
    int a[5];
    processArray(a,top);
    return 0;

}
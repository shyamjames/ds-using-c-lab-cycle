#include <stdio.h>

int global_var = 10; // global variable

void storageClasses(){
    int local_var = 5; // local variable: accessible only inside this function
    static int static_var = 0;     // Static variable: retains its value between function calls
    register int reg_var = 1; // Register variable: stores in cpu resgisters.


    // increment each variable
    local_var++;
    static_var++;
    global_var++;
    reg_var++;

    printf("Local Variable: %d\n",local_var);
    printf("Static Variable: %d\n",static_var);
    printf("Global variable: %d\n",global_var);
    printf("Register variable: %d\n",reg_var);
}

int main(){
    printf("First call to storageClasses function:\n");
    storageClasses();

    printf("\nFirst call to storageClasses function:\n");
    storageClasses();

    return 0;
}
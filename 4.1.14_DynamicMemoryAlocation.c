#include<stdlib.h> //malloc - memory allocation 
int main(void) {
    int * intptr;
    double * doubleptr;

    
    /*malloc(4);  //malloc is a function in C that makes the Dynamic memory allocation
    malloc(1); //malloc only reserves space memory in multiples of 4 
    malloc(5);
    malloc(sizeof(int));
    malloc(sizeof(double));*/
    intptr = (int *) malloc(sizeof(int));
    * intptr = 5;
    doubleptr = (double *) malloc(sizeof(double));
    * doubleptr = 9.0;
    return 0;
}

/* stack x reep : variables are stored in the stack 
- reep of the memory location

*/
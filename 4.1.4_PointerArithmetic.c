#include<stdio.h>

int main(void) {
    int array[] = {6,2,-4,8,5,1};
    int *ptr , *ptr2;
    printf("Array contains %d, %d, ... , %d\n", array[0], array[1], array[5]);
    printf("These are stored at %p , %p, .., %p\n", &array[0],&array[1],&array[5]);
    printf("Array is %p.\n",array);
    //important: array equals &array[0]
    ptr = array;
    ptr2 = &array[0]; //ptr = ptr2

    *ptr = 10; //array[0]
    *(ptr + 1) = 5; //array[0+1] = array[1]
    *(ptr + 2) = -1;  //array[2]

    //outra maneira de fazer a mesma coisa:
    *array = 3;
    *(array + 1) = 10;
    *(array + 2) = 99;

    ptr++;
    *ptr = 7;

    ptr += 3;
    
    return 0;

}
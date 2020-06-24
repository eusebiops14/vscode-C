#include<stdio.h>
int main(void){

    short a[3] = {234,655,843};
    short b[2] = {12,62};
    short c[4] = {3456,3467,23,276};
    short * arrays[3] = {a,b,c}; //array que contem os arrays a,b e c.

    *arrays[0] = 5; //*arrays[0] = a[0] = arrays[0][0]
    *(arrays[0] + 1) = 6; //*(arrays[0]+1) = a[1] = arrays[0][1]
    *(arrays[0] + 2) = 7; //*(arrays[0]+2) = a[2] = arrays[0][2]

    *arrays[1] = 3; //*arrays[1] = b[0] = arrays[1][0]
    *(arrays[1]+1) = 4;//*(arrays[1]+1) = b[1] = arrays[1][1]

    //*arrays[2] = c[0] = arrays[2][0]
    //*(array[2]+1) = c[1] = arrays[2][1]
    //*(array[2]+2) = c[2] = arrays[2][2]
    //*(array[2]+3) = c[3] = arrays[2][3]
    printf("ok!");
    return 0;
}
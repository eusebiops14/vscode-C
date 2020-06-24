#include <stdio.h>
void setToZero(short **);
int main(void){

    short a[3] = {1245, 1924, 234};
    short b[2] = {24, 256};
    short * t[2] = {a,b}; //pointer of a pointer - t is a pointer, that means: *t[] is a pointer of a pointer (represented with two * : **) 
  
    setToZero(t);


    return 0;
}

void setToZero(short ** t) {
    //printf("%c",*(*t)); 
    *(*t) = 0; // *(*t) == *(t[0]+0) == a[0] == t[0][0] -> aponta para o primeiro elemento dentro de a, ou seja 1245
    *((*t)+1) = 0; // *((*t)+1) == *(t[0]+1) == a[1] == t[0][1]
    *((*t)+2) = 0; // *((*t)+2) == *(t[0]+2) == a[2] == t[0][2]

    *(*(t+1)+0) = 0; //*(*(t+1)+0) == *(t[1]+0) == b[0] == t[1][0]
    *(*(t+1)+1) = 0 ;  // (**(t+1)+1) == *(t[1]+1) == b[1] == t[1][1]


}
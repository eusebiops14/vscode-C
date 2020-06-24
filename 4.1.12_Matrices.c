#include<stdio.h>
int main(void){
    int matrix[2][3];
    int line =0 , col =0 ;

    for (line = 0 ; line < 2 ; line++) {
        for(col =0; col < 3; col++){
            scanf("%d",&matrix[line][col]);
        }
    }

    for (line = 0 ; line < 2 ; line++) {
        for(col =0; col < 3; col++){
            printf(" %d ",matrix[line][col]);
        }
        printf("\n");
    }
    return 0;
}
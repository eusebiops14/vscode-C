#include<stdio.h>
int main(void){
    char words[3][40];
    int i =0;
    int j = 0;

    for (i=0;i<3;i++){
        scanf("%s",&words[i]);
    }

   

    for(j = 3; j>=0;j--){
        printf("%s ",words[j]);
    }
    return 0;
}
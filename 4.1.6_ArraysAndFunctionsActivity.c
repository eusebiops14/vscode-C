#include <stdio.h>

void behind(int *, int);

int main(void) {
    int array[10];
    int N, i;
    
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &array[i]);
    }
    behind(array, N);
    for (i=0; i<N; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}


/* Write your function behind() here: */
void behind(int * ptr , int nbPlayers){
    int k =0;
    int j=0;
    int n=0;
    int topScore = 0;

//printf("------------------------------>%d\n",*(ptr+1));


    for (j=0;j<nbPlayers-1;j++){
        for (k=0;k<nbPlayers-1;k++){
            //printf("%d \n",*(ptr+(k+1)));
            if (*(ptr + k) < (*(ptr + (k+1)))) {  
            topScore =  *(ptr + (k+1));
            }
        }
    }
    //printf("topscore = %d\n",topScore);

    for (n=0;n<nbPlayers;n++) {
        *(ptr +n) = topScore - (*(ptr + n));
    }


}

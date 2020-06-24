#include<stdio.h>
int main(void) {
    char a[4];
    char b[6];
    char c[9];

    char * words[3] = {a,b,c};

    printf("Please enter a word with at most 3 letters: ");
    scanf("%s",a); //nao precisa do "&" na frente do a pois "a" já é um endereço (aponta para o primeiro elemento do array a)
    printf("Please enter a word with at most 5 letters: ");
    scanf("%s",b); //nao precisa do "&" na frente do a pois "a" já é um endereço (aponta para o primeiro elemento do array a)
    printf("Please enter a word with at most 8 letters: ");
    scanf("%s",c); //nao precisa do "&" na frente do a pois "a" já é um endereço (aponta para o primeiro elemento do array a)
    
    printf("You entered: \n");
    printf("%s %s %s.\n",a,b,c);
    printf("%s %s %s.\n",words[0],words[1],words[2]);
    
    return 0;
}
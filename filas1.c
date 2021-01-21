//FILA POR ARRANJOS

#define MAXTAM 100 //colocar 2 elevado a 15 depois
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/*typedef int TChave;
typedef struct {
    TChave Chave;
}TItem;*/
//typedef int TIndice;


typedef int TApontador;

typedef struct{
    int indiceLutador;
    int forcaLutador;    
}TLutador;


typedef struct {
    TLutador Lutador[MAXTAM];
    TApontador Frente, Tras;
}TFilaLutadores;

void TFila_Inicia(TFilaLutadores *pFila) {
    pFila->Frente = 0;
    pFila->Tras = 0;
   // pFila->Lutador.indiceLutador = 0;
}

int TFila_EhVazia(TFilaLutadores *pFila) {
    return (pFila->Frente == pFila->Tras);
}

int TFila_Tamanho(TFilaLutadores *pFila) {
    return ((pFila->Tras >= pFila->Frente) ?
    (pFila->Tras - pFila->Frente) :
    (MAXTAM + pFila->Tras - pFila->Frente));
}

int TFila_Enfileira(TFilaLutadores * pFila, int  forca) {
    if (pFila->Frente == (pFila->Tras +1) % MAXTAM)
    printf("ERRO: FILA CHEIA");
    return 0; /*FILA CHEIA */
    
    pFila->Lutador[pFila->Tras].forcaLutador = forca ; 
    pFila->Lutador[pFila->Tras].indiceLutador = pFila->Tras;
    pFila->Tras = ((pFila->Tras + 1)) % MAXTAM ;
    
    //pFila->Lutador[pFila->Tras] = x;
    //pFila->Lutador.forcaLutador[pFila->Tras] = forca ;
    return 1;
}

int TFila_Desenfileira(TFilaLutadores * pFila, int *pX) {
    if (TFila_EhVazia(pFila)){
    return 0;
    }
    *pX = pFila->Frente;
    pFila->Frente = (pFila->Frente + 1) % MAXTAM;
    return 1;
}
    
int main () {
   /* int Ncompetidores;
    int ExpoenteN;
    int Krecuperacao;
    int k =0;
    int forcaInicialPi;
    int maxtam = pow(2,15);
    int ArranjoForcaLutador[maxtam];*/
    

    /*
    scanf("%d %d",&ExpoenteN,&Krecuperacao);

    Ncompetidores = pow(2,ExpoenteN);
    */

    TFilaLutadores MinhaFilaDeLutadores; //= (TFila*)malloc(sizeof(TFila));
    
    TFila_Inicia(&MinhaFilaDeLutadores);
    /*
    int ForcaLutadorX1 , ForcaLutadorX2;
    

    for(k=0; k < Ncompetidores; k++) {
        scanf("%d",&forcaInicialPi);
        
        TFila_Enfileira(&MinhaFila,forcaInicialPi);

    } 

    for (k=0; k < Ncompetidores-1; k++) {
        if
    }


    printf("tamanho da fila: %d", TFila_Tamanho(&MinhaFila));
    while (TFila_EhVazia(&MinhaFila) == 0) {
        TFila_Desenfileira(&MinhaFila,ForcaLutadorX1);
        TFila_Desenfileira(&MinhaFila,ForcaLutadorX2);
        if (ForcaLutadorX1 > ForcaLutadorX2) {
            TFila_Enfileira(&MinhaFila,)
        }
    }


    */
   int inteiro;
    TFila_Enfileira(&MinhaFilaDeLutadores,1);
    TFila_Enfileira(&MinhaFilaDeLutadores,2);
    TFila_Enfileira(&MinhaFilaDeLutadores,3);
    TFila_Enfileira(&MinhaFilaDeLutadores,4);
    printf("Tamanho da fila: %d\n", TFila_Tamanho(&MinhaFilaDeLutadores));
    
    TFila_Desenfileira(&MinhaFilaDeLutadores,&inteiro);
    printf("Valor retirado da fila = %d\n", inteiro);
    TFila_Desenfileira(&MinhaFilaDeLutadores,&inteiro);
    printf("Valor retirado da fila = %d\n", inteiro);
    TFila_Desenfileira(&MinhaFilaDeLutadores,&inteiro);
    printf("Valor retirado da fila = %d\n", inteiro);
    if (TFila_EhVazia(&MinhaFilaDeLutadores)) {
        printf("A FILA ESTÁ VAZIA\n");
    }
    
    return 0;
}

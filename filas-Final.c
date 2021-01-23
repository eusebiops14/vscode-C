//FILA POR ARRANJOS

#define MAXTAM 32768 //colocar 2 elevado a 15 depois
#include<stdio.h>
#include<stdlib.h>
#include<math.h>



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
    pFila->Frente = 1;
    pFila->Tras = 1;
   
}

int TFila_EhVazia(TFilaLutadores *pFila) {
    if (pFila->Frente == pFila->Tras) {
        return 1;
    }else {
        return 0;
    }
}

int TFila_Tamanho(TFilaLutadores *pFila) {
    return ((pFila->Tras >= pFila->Frente) ?
    (pFila->Tras - pFila->Frente) :
    (MAXTAM + pFila->Tras - pFila->Frente));
}

int TFila_Enfileira(TFilaLutadores * pFila, int  forca) {
    if (pFila->Frente == (pFila->Tras +1) % MAXTAM){
    //printf("ERRO: FILA CHEIA");
    return 0; 
    }

    pFila->Lutador[pFila->Tras].forcaLutador = forca ; 
    pFila->Lutador[pFila->Tras].indiceLutador = pFila->Tras;
    pFila->Tras = ((pFila->Tras + 1)) % MAXTAM ;
    
     return 1;
}

int TFila_Reenfileira(TFilaLutadores * pFila , int forca , int indice) {
    pFila->Lutador[pFila->Tras].forcaLutador = forca ; 
    pFila->Lutador[pFila->Tras].indiceLutador = indice;
    pFila->Tras = ((pFila->Tras + 1)) % MAXTAM ;

    return 1;
}

int TFila_Desenfileira(TFilaLutadores * pFila, int *forca, int *indice) {
    if (TFila_EhVazia(pFila)){
        
    return 0;
    }
    *forca = pFila->Lutador[pFila->Frente].forcaLutador;
    *indice = pFila->Lutador[pFila->Frente].indiceLutador;
    pFila->Frente = (pFila->Frente + 1) % MAXTAM;
    return 1;
}
    
int main () {
    int Ncompetidores;
    int ExpoenteN ;
    int Krecuperacao;
    int k =0;
    int i = 0;
    int forcaInicialPi;
    

    scanf("%d %d",&ExpoenteN,&Krecuperacao);
    if (ExpoenteN > 15) {
        return 0; //erro
    }

    Ncompetidores = pow(2,ExpoenteN);
    

    TFilaLutadores MinhaFilaDeLutadores;
    
    TFila_Inicia(&MinhaFilaDeLutadores);
    
        
    int ForcaLutadorX1 , ForcaLutadorX2, indiceX1, indiceX2;
    

    for(k=0; k < Ncompetidores; k++) {
        scanf("%d",&forcaInicialPi);
        if (forcaInicialPi > 1000) {
            return 0;
        }
        TFila_Enfileira(&MinhaFilaDeLutadores,forcaInicialPi);
       
    } 


    
    int contador = 1;
    while (TFila_Tamanho(&MinhaFilaDeLutadores) > 1){   

       TFila_Desenfileira(&MinhaFilaDeLutadores,&ForcaLutadorX1,&indiceX1);
       TFila_Desenfileira(&MinhaFilaDeLutadores,&ForcaLutadorX2,&indiceX2);
       printf("\n\nCONFRONTO NÚMERO %d\n", contador);
       contador++; 
       printf("Força Desenfileirada x1: %d //// Indice desenfileirado x1: %d\n",ForcaLutadorX1,indiceX1);
       printf("Força Desenfileirada x2: %d //// Indice desenfileirado x2: %d\n",ForcaLutadorX2,indiceX2);

        if (ForcaLutadorX1 > ForcaLutadorX2) { //lutador1 vence
            if ((ForcaLutadorX1 - ForcaLutadorX2 + Krecuperacao) <= ForcaLutadorX1){
                ForcaLutadorX1 = (ForcaLutadorX1 - ForcaLutadorX2) + Krecuperacao;
            }
            TFila_Reenfileira(&MinhaFilaDeLutadores,ForcaLutadorX1,indiceX1);
            printf("Forca ReEnfileirada: %d ///// indice Reenfileirado: %d \n",ForcaLutadorX1, indiceX1);
            
        }else if(ForcaLutadorX1 < ForcaLutadorX2) { //lutador2 vence
            if ((ForcaLutadorX2-ForcaLutadorX1+Krecuperacao) <= ForcaLutadorX2){
                ForcaLutadorX2 = ForcaLutadorX2 - ForcaLutadorX1 + Krecuperacao;
            }
            TFila_Reenfileira(&MinhaFilaDeLutadores,ForcaLutadorX2,indiceX2);
            printf("Forca ReEnfileirada: %d //// indice Reenfileirado: %d\n",ForcaLutadorX2, indiceX2);
        
        }else if (ForcaLutadorX1 == ForcaLutadorX2) {
            if (indiceX1 > indiceX2) { // x2 vence pois tem menor indice
                if ((ForcaLutadorX2-ForcaLutadorX1+Krecuperacao) <= ForcaLutadorX2){
                    ForcaLutadorX2 = ForcaLutadorX2 - ForcaLutadorX1 + Krecuperacao;
                }
                TFila_Reenfileira(&MinhaFilaDeLutadores,ForcaLutadorX2,indiceX2);
                printf("Forca ReEnfileirada: %d //// indice Reenfileirado: %d\n",ForcaLutadorX2, indiceX2);
            }else if ( indiceX1 < indiceX2) { //x1 vence pois tem menor indice
                if ((ForcaLutadorX1 - ForcaLutadorX2 + Krecuperacao) <= ForcaLutadorX1){
                    ForcaLutadorX1 = ForcaLutadorX1 - ForcaLutadorX2 + Krecuperacao;
                }
                TFila_Reenfileira(&MinhaFilaDeLutadores,ForcaLutadorX1,indiceX1);
                printf("Forca ReEnfileirada: %d //// indice Reenfileirado: %d\n",ForcaLutadorX1, indiceX1);
            }

        } 
             
        
    }
    
    
    int indiceVencedor , forcaVencedor, tam;    
    TFila_Desenfileira(&MinhaFilaDeLutadores,&forcaVencedor, &indiceVencedor);
    
    printf("forca vencedor : %d //// indice vencedor: %d\n",forcaVencedor, indiceVencedor);
    printf("Tamanho final da fila: %d\n",TFila_Tamanho(&MinhaFilaDeLutadores));
    printf("%d\n",indiceVencedor);
  
    return 1;
}

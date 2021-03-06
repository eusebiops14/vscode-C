//FILA POR ARRANJOS

#define MAXTAM 32767 //colocar 2 elevado a 15 depois
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>



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

int TFila_Enfileira(TFilaLutadores * pFila, TLutador lutador) {
    if (pFila->Frente == (pFila->Tras +1) % MAXTAM){
        return 0; 
    }
    pFila->Lutador[pFila->Tras] = lutador;
    pFila->Tras = ((pFila->Tras + 1)) % MAXTAM ;
    
     return 1;
}



int TFila_Desenfileira(TFilaLutadores * pFila, TLutador *lutador) {
    if (TFila_EhVazia(pFila)){
        
    return 0;
    }
  
    *lutador = pFila->Lutador[pFila->Frente]; 
    
    pFila->Frente = (pFila->Frente + 1) % MAXTAM;
    return 1;
}
    
int main () {
    int Ncompetidores;
    int ExpoenteN ;
    int Krecuperacao;
    int k =0;
    //int i = 0;
    int forcaInicialPi;
    

    scanf("%d %d",&ExpoenteN,&Krecuperacao);
    if (ExpoenteN > 15) {
        return 0; 
    }

    Ncompetidores = pow(2,ExpoenteN);
    //printf("Quantidade de competidores : %d\n", Ncompetidores);

    TFilaLutadores MinhaFilaDeLutadores;
    TLutador lutador;
    
    TFila_Inicia(&MinhaFilaDeLutadores);
    
        
    int ForcaLutadorX1 , ForcaLutadorX2, indiceX1, indiceX2;
    

    for(k=0; k < Ncompetidores; k++) {
        //forcaInicialPi = 10 ;
        scanf("%d",&forcaInicialPi);
        lutador.forcaLutador = forcaInicialPi;
        lutador.indiceLutador = k+1;


        //if (forcaInicialPi > 1000) {
        //    return 0;
        //}

        TFila_Enfileira(&MinhaFilaDeLutadores,lutador);
        //printf("Tamanho da Fila: %d\n",TFila_Tamanho(&MinhaFilaDeLutadores));
    } 
    


    
    //int contador = 1;
    //while (TFila_Tamanho(&MinhaFilaDeLutadores) != 1 ){   
    while (TFila_EhVazia(&MinhaFilaDeLutadores) == 0){    
       TFila_Desenfileira(&MinhaFilaDeLutadores,&lutador);
       ForcaLutadorX1 = lutador.forcaLutador;
       indiceX1 = lutador.indiceLutador;

       
       TFila_Desenfileira(&MinhaFilaDeLutadores,&lutador);
       ForcaLutadorX2 = lutador.forcaLutador;
       indiceX2 = lutador.indiceLutador;
       //printf("Força Desenfileirada x1: %d //// Indice desenfileirado x1: %d\n",ForcaLutadorX1,indiceX1);
       //printf("Força Desenfileirada x2: %d //// Indice desenfileirado x2: %d\n",ForcaLutadorX2,indiceX2);
       
       

        if (ForcaLutadorX1 > ForcaLutadorX2) { //lutador1 vence
            if ((ForcaLutadorX1 - ForcaLutadorX2 + Krecuperacao) <= ForcaLutadorX1){
                ForcaLutadorX1 = (ForcaLutadorX1 - ForcaLutadorX2) + Krecuperacao;
                lutador.indiceLutador = indiceX1;
                lutador.forcaLutador = ForcaLutadorX1; //atualiza a forca do lutador vencedor
                
            }else{
                lutador.indiceLutador = indiceX1;
                lutador.forcaLutador = ForcaLutadorX1;
            }
            //printf("X1 venceu- indice enfileirado: %d //// Forca enfileirada: %d\n",indiceX1,ForcaLutadorX1);
            TFila_Enfileira(&MinhaFilaDeLutadores,lutador);
            
            
        }else if(ForcaLutadorX1 < ForcaLutadorX2) { //lutador2 vence
            if ((ForcaLutadorX2-ForcaLutadorX1+Krecuperacao) <= ForcaLutadorX2){
                ForcaLutadorX2 = ForcaLutadorX2 - ForcaLutadorX1 + Krecuperacao;
                lutador.indiceLutador = indiceX2;
                lutador.forcaLutador = ForcaLutadorX2;
            }else{
                lutador.indiceLutador = indiceX2;
                lutador.forcaLutador = ForcaLutadorX2;
            }
            //printf("X2 venceu- indice enfileirado: %d //// Forca enfileirada: %d\n",indiceX2,ForcaLutadorX2);
            TFila_Enfileira(&MinhaFilaDeLutadores,lutador);
            
        
        }else if (ForcaLutadorX1 == ForcaLutadorX2) {
            if (indiceX1 > indiceX2) { // x2 vence pois tem menor indice
                if ((ForcaLutadorX2-ForcaLutadorX1+Krecuperacao) <= ForcaLutadorX2){
                    ForcaLutadorX2 = ForcaLutadorX2 - ForcaLutadorX1 + Krecuperacao;
                    lutador.indiceLutador = indiceX2;
                    lutador.forcaLutador = ForcaLutadorX2;
                }else {
                    lutador.indiceLutador = indiceX2;
                    lutador.forcaLutador = ForcaLutadorX2;
                }
                //printf("X2 venceu com menor indice- indice enfileirado: %d //// Forca enfileirada: %d\n",indiceX2,ForcaLutadorX2);
                TFila_Enfileira(&MinhaFilaDeLutadores,lutador);
                
            }else if ( indiceX1 < indiceX2) { //x1 vence pois tem menor indice
                if ((ForcaLutadorX1 - ForcaLutadorX2 + Krecuperacao) <= ForcaLutadorX1){
                    ForcaLutadorX1 = ForcaLutadorX1 - ForcaLutadorX2 + Krecuperacao;
                    lutador.indiceLutador = indiceX1;
                    lutador.forcaLutador = ForcaLutadorX1;
                }else {
                     lutador.indiceLutador = indiceX1;
                    lutador.forcaLutador = ForcaLutadorX1;
                }
                //printf("X1 venceu com menor indice- indice enfileirado: %d //// Forca enfileirada: %d\n",indiceX1,ForcaLutadorX1);
                TFila_Enfileira(&MinhaFilaDeLutadores,lutador);
                
            }

        } 
             
        
    }
    
    
    int indiceVencedor;    
    TFila_Desenfileira(&MinhaFilaDeLutadores,&lutador);
    indiceVencedor = lutador.indiceLutador;
    
    printf("%d\n",indiceVencedor);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void exibirPoltronas(int plt[3][3]){
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            if (plt[i][j]<0){
                printf("[  X ]");
            }else{
                printf("[ %i ]", plt[i][j]);
            }
        }                                                                                    
        printf("\n");
    }
}

void verificaEscolha(int escolha, int plt[3][3]){
    if (escolha < 1 || escolha > 9){
        printf("POLTRONA INVALIDA! ESCOLHA DE 1 A 9.\n");
        return;
    }
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
             if (plt[i][j] == escolha){
                plt[i][j] = -escolha;
                printf("POLTRONA RESERVADA!\n");
            }else if (plt[i][j] == -escolha){
                printf("POLTRONA JA RESERVADA! ESCOLHA OUTRA!\n");
                }
            }
        }                                                                                    
    }   

int verificarLotacao(int plt[3][3]){
    int reservadas = 0; 
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            if (plt[i][j]<0){
                reservadas++;
            }
        }
    }         
    return reservadas;                                                                     
}   


int main(){
    int plt[3][3];
    int ultimo = 0;
    int c = 1;
    int escolha;
    char continuar;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            plt[i][j] = c;
            c++;
        }
    }
    do{
        int reservadas = verificarLotacao(plt);
        if (reservadas>=9){
            printf("TODAS AS POLTRONAS ESTÃO OCUPADAS\n");
            break;
        }
        exibirPoltronas(plt);
        printf("Qual poltrona deseja reservar?\n");
        scanf( "%i", &escolha);
        verificaEscolha(escolha, plt);
        printf("Deseja continuar?[S/N]\n");
        scanf(" %c", &continuar);
    }while (continuar=='s' || continuar=='S');
    printf("SAINDO...");
    return 0;
}
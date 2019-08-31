/******************************************************************************

ENUNCIADO:
Criar dois vetores de inteiro de 100 posições.
Preencher o primeiro vetor com valores entre 0 e 9, inclusive o 0 e o 9, enquanto o usuário desejar.
Preencher o segundo vetor com valores entre 0 e 9, inclusive o 0 e o 9, enquanto o usuário desejar.
Verifique se dentro do vetor1 contém a mesma sequência do vetor2 ou vice-versa. Procurar a menor sequência dentro da maior sequência.

QUESTÕES:
- como codar "enquanto o usuário desejar", i.e., como sair do loop
- se for p/ sair do loop com um número, como retirar esse número do array (remover úlitmo item ativo?)
- pedir os 2 vetores com uma única função

shortcuts:
Ctrl + D | delete line

*******************************************************************************/

#include <stdio.h>
#include <locale.h> // para acentos

int contido(int vetor1[100], int vetor2[100], int tam1, int tam2);

int main()
{
	setlocale(LC_ALL,"");
    int vetor1[100], vetor2[100], i, j, counter1 = 0, counter2 = 0, counter, resultado;
    
    printf("Você está no VETOR 1.\n");
    printf("Digite 99 para VETOR 2.\n\n");
    
    // vetor 1 - recebendo valores (até possivelmente 100)
    for (i = 0; i < 100; ++i){
        
        printf("Digite o %dº numero: ", i+1);
        scanf("%d", &vetor1[i]);
        counter1 += 1;
        
        if (vetor1[i] == 99) {
            //vetor1[i] = NULL;
            counter1 -= 1;
            break;
        }
        else if (vetor1[i] > 9 || vetor1[i] < 0) {
            printf("\nERRO: Número deve estar entre 0 e 9.\n");
            i -= 1;
            counter1 -= 1;
        }
    }
    
    // imprimindo vetor1 de maneira organizada
//    counter = i;
//    for (i = 0; i <= counter; i++) {
//    	if (i == 0) {
//    		printf("\nVetor 1 = {%d,", vetor1[i]);
//		}
//    	else if (i == counter) {
//    		printf(" %d}", vetor1[i]);
//		}
//		else {
//	    printf(" %d,", vetor1[i]);
//		}
//    }
    
    // vetor 2 - recebendo valores (até possivelmente 100)
    printf("\n\nVocê está no VETOR 2.\n");
    printf("Digite 99 para finalizar\n");
    
    for (i = 0; i < 100; ++i){
        
        printf("Digite o %dº numero: ", i+1);
        scanf("%d", &vetor2[i]);
        counter2 += 1;
        
        if (vetor2[i] == 99) {
            break;
            counter2 -= 1;
        }
        
        if (vetor2[i] > 9 || vetor2[i] < 0) {
            printf("\nERRO: Número deve estar entre 0 e 9.\n");
            i -= 1;
            counter2 -= 1;
        }
    }
    
	// SIM ou NÃO
	resultado = contido(vetor1, vetor2, counter1, counter2);
	
    if(resultado != 0)
    	printf("\n\nSIM\n");
    else
        printf("\n\nNAO\n");
	
	
	
	
int contido(int vetor1[100], int vetor2[100], int tam1, int tam2) {

        int resultado = 0, i , j = 0, voltar;

        if (tam1 > tam2){
	        for(i=0; i < tam1; i++) {
	            if(vetor1[i] == vetor2[j] && vetor2[j] >= 0 && vetor2[j] <= 9 )
	               j++;
	
	            else if (vetor1[i] != vetor2[j] && vetor2[j] >= 0 && vetor2[j] <= 9 ){
	               if (j != 0)
	               	i = i - j;
	            	j = 0;
				}
	
	            if (j == tam2)
	                resultado++;
			}
		}


        else {

         for(i=0;i<tam2;i++){

            if(vetor2[i] == vetor1[j] && vetor1[j] >= 0 && vetor1[j] <= 9 ) {
               j++;
			}

            else if (vetor2[i] != vetor1[j] && vetor1[j] >= 0 && vetor1[j] <= 9 ) {

              if (j != 0)
               i = i - j;

               j = 0;
            }

            if (j == tam1)
                resultado++;
		}
		}
		
    return 0;
    
}


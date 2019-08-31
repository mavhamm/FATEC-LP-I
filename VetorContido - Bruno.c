#include <stdio.h>
#include <locale.h> // para acentos

int leia(int vetor[100]);
int imprima(int vetor[100]);
int tamanho(int vetor[100]);
int contido(int vetor1[100], int vetor2[100], int tam1, int tam2);

 void main (){
 	setlocale(LC_ALL,"");


        int vetor1[100], vetor2[100],i, tamvet1, tamvet2, resultado;


        for(i=0;i<100;i++){
            vetor1[i] = -1;
            vetor2[i] = -1;

        }
        // Leia vet 1
        leia(vetor1);
        // Leia vet 2
        leia(vetor2);

        // tamanho dos vetores
        tamvet1 = tamanho(vetor1);
        tamvet2 = tamanho(vetor2);

        // Veja se um ta contido no outro

        resultado = contido(vetor1,vetor2,tamvet1, tamvet2);

        if(resultado != 0)
            printf("\n\nSIM\n");
        else
            printf("\n\nNAO\n");


    }

int leia(int vetor[100]){

    int i = 0, para = -1;

        do {
            scanf("%i",&vetor[i]);
            if(vetor[i] < 0 || vetor[i] > 9)
            para = 1;
            i++;

          } while(para == -1);

    return vetor[100];

}

int tamanho(int vetor[100]){

     int para = -1, cont = 0;

        do{

            if(vetor[cont] < 0 || vetor[cont] > 9)
            para = 1;

            else
               cont++;

          }while(para == -1);

         return cont;
     }

int contido(int vetor1[100], int vetor2[100], int tam1, int tam2){

        int resultado = 0,i,j=0, voltar;

        if (tam1 > tam2){

        for(i=0;i<tam1;i++){
            if(vetor1[i] == vetor2[j] && vetor2[j] >= 0 && vetor2[j] <= 9 )
               j++;

            else if (vetor1[i] != vetor2[j] && vetor2[j] >= 0 && vetor2[j] <= 9 ){

               if (j != 0)
               i = i - j;

                j = 0;}


            if (j == tam2)
                resultado++;}}


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

        return resultado;
}

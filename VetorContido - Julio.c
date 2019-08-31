#include <stdio.h>
#include <locale.h> // para acentos

int recebe(int* vetor);

int procura(int* vetor1, int tam1, int* vetor2, int tam2);

int main(){
	
	setlocale(LC_ALL,"");
	
    int vet1[100], vet2[100], 
		N1, N2, //tamanho dos vetores
		sim;    //verdadeiro ou falso 


    printf("PRIMEIRO VETOR:\n");
	N1 = recebe(vet1);
    
    
    printf("SEGUNDO VETOR:\n");
    N2 = recebe(vet2);
	
	
    if(N1 < N2){
        sim = procura(vet1, N1, vet2, N2);
    }
    else{
        sim = procura(vet2, N2, vet1, N1);
    }


    if(sim)
        printf("SIM\n");
    else
        printf("NAO\n");
	

    return 0;
}

int recebe(int* vetor){
	int tam, i;
	
	
	printf("Quantos elementos deseja incluir no vetor? (Maximo = 100)\n");
    scanf("%d", &tam);
    while (tam > 100 || tam < 1) {
        printf("Quantidade de elementos invalida, digite um valor valido \n");
        scanf("%d", &tam);
    }
	
	
	printf("Insira os elementos do vetor(somente numeros de 0 a 9):\n");
    for(i=0; i<tam; i++){
		printf("%dº elemento: ", i+1);
        scanf("%d", &vetor[i]);
		while (vetor[i] > 9 || vetor[i] < 0) {
			printf("Numero invalido, insira um valor valido \n");
			printf("%dº elemento: ", i+1);
			scanf("%d", &vetor[i]);
        }
    }
	
	printf("\n");
	
	return tam;
}

int procura(int* vetor1, int tam1, int* vetor2, int tam2){
	int i, j;
	
	j = 0;
	for(i=0; i<tam2; i++){
		if(vetor1[j]==vetor2[i])
			j++;
		else if(j != tam1)
			j = 0;
	}
	
	if(j==tam1)
        return 1;
    else
        return 0;
	
}

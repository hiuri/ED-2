//Trab HIURI & LEONAM

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include "biblioteca.h"


//Funcao principal com a manipulacao dos arquivos de entrada
int main(int argc, char *argv[ ]){
	FILE *arq;
	arq =fopen(argv[3], "rt");//Abertura do arquivo
	if( arq==NULL){
		printf("Falha na leitura do arquivo");
	}
	//leitura dos dados
	int result, aux,tamanho_vet,cont;
	int top = atoi(argv[2]); //quantidade de elementos a serem exibidos no final
	aux = fscanf(arq, "%d",&tamanho_vet);//leitura da quantidade de entradas
	int vet[tamanho_vet];
	
	for(cont=0;cont<tamanho_vet;cont++){//Preenchimento do vetor
		result = fscanf(arq, "%d", &aux);
		vet[cont]=aux;
	}

	//printf("antes\n");
	int tamanho = strlen(argv[1]);
	int i; 
	char ult_ord;
	long int compara, trocas;
	long int* comp;
	long int* troca;
	comp = &compara;
	troca = &trocas;
	clock_t t;
	double time;
	//printf("AQUI\n");
	char *string = argv[1];
	for (i=0;i<tamanho;i++){//acoes passadas na entrada
		switch (string[i])
		{
   			case 'a':
				todos(vet,tamanho_vet, top, comp, troca, argv[4]);
   				break;

			case 's':
			   	*troca = 0;
    			*comp = 0;
				t = clock(); // armazena tempo  
     			selection_sort(vet, tamanho_vet, top, comp, troca);
				t = clock() - t; // tempo final - tempo inicial
				time = ((double)t)/((clock_t)(1000000)); //Converte tempo em segundos
				ult_ord = 's'; // armazena a ultima ordenação feita pelo sistema
				 //printf("%d\n", tamanho_vet);
   				break;
			
			case 'i':
				*troca = 0;
    			*comp = 0;
				t = clock(); // armazena tempo  
				insertion_sort(vet, tamanho_vet, top, comp, troca);
				t = clock() - t; // tempo final - tempo inicial
				time = ((double)t)/((clock_t)(1000000)); //Converte tempo em segundos
				ult_ord = 'i'; // armazena a ultima ordenação feita pelo sistema
				 //printf("%d\n", tamanho_vet);
				break;
			
			case 'e':
				*troca = 0;
    			*comp = 0;
				t = clock(); // armazena tempo 
				shell_sort(vet,tamanho_vet, top, comp, troca);
				t = clock() - t; // tempo final - tempo inicial
				time = ((double)t)/((clock_t)(1000000)); //Converte tempo em segundos
				ult_ord = 'e'; // armazena a ultima ordenação feita pelo sistema
				break;
			
			case 'q':
				*troca = 0;
    			*comp = 0;
				t = clock(); // armazena tempo 
				quick_sort(vet,0,tamanho_vet-1, comp, troca);
				t = clock() - t; // tempo final - tempo inicial
				time = ((double)t)/((clock_t)(1000000)); //Converte tempo em segundos
				ult_ord = 'q'; // armazena a ultima ordenação feita pelo sistema
				 //printf("%d\n", tamanho_vet);
				break;
			
			case 'h':
				*troca = 0;
    			*comp = 0;
				t = clock(); // armazena tempo 
				heap_sort(vet,tamanho_vet, top, comp, troca);
				t = clock() - t; // tempo final - tempo inicial
				time = ((double)t)/((clock_t)(1000000)); //Converte tempo em segundos
				ult_ord = 'h'; // armazena a ultima ordenação feita pelo sistema
				break;
			
			case '1'://Impressao dos T valores ordenados
				/*for(i=0;i<top;i++){
					printf("%d\n", vet[i]);
				}*/
				imprime(vet, tamanho_vet, argv[3], comp, troca, '1', top, time, ult_ord);
				break;
   			
			case '2':
				imprime(vet, tamanho_vet, argv[3], comp, troca, '2', top, time, ult_ord);
				break;

			case '3':
				imprime(vet, tamanho_vet, argv[3], comp, troca, '3', top, time, ult_ord);	   
				break;

			default:
     			break;
		};
	}


	fclose(arq);
	return 0; 
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "str.h"
#include "suffix.h"

int main(int argc, char *argv[ ]){
	FILE *arq;
	FILE *s;
	arq = fopen(argv[2], "rt"); //Abertura do arquivo
	if(arq == NULL){
		printf("falha na abertura do arquivo");
	}
	int contexto = atoi(argv[3]);
	char querry[50];
	strcpy(querry,argv[4]);
	long int i=0,j, result;
	long int N;
	result = fscanf(arq,"%ld", &N);//leitura do numero de caracteres
	char texto[N], char_aux;
	int cont_espaco = 0;
	result = fscanf(arq, "%c", &char_aux); //Consumindo o primeiro '\n' 
	while (!feof(arq))
    {
	// Leitura ja retirando os espacos excessivos e as quebras de linha
		result = fscanf(arq, "%c", &char_aux);  // lendo caracter a caractere
		if(char_aux != '\n'){
			if(char_aux != ' '){
				texto[i] = char_aux;
				i++;
				cont_espaco = 0;
			}else if(cont_espaco == 0){
				texto[i] = ' ';
				i++;
				cont_espaco = 1;
			}
		}else if(cont_espaco == 0){
			texto[i] = ' ';
			i++;
			cont_espaco = 1;
		}
	}
	texto[i] = '\n'; //fim da String de entrada
	fclose(arq); //terminada a leitura do arquivo de entrada

	//LOGICA PRINCIPAL
	String* string = create_string(texto); //Criando a Struct String gigante
	Suffix** array = create_suf_array(string,i);//i guarda o tamanho da string sem os espacos e quebras
	//imprime(array,i);

	//NAO CONSEGUI USAR A QSORT!!!

	//qsort(array,i,sizeof(struct Suffix*),compare_suffix);
	
	



	//int achou;
	//achou = buscabinaria(i, array, querry);

	if(strcmp(argv[1],"-a") == 0){
		imprime(array,i); //Impressao em arquivo
	}else if(strcmp(argv[1],"-o") == 0){
		booble_sort(array, i);
		imprime(array,i); //Impressao em arquivo
	}else if(strcmp(argv[1],"-r") == 0){
		clock_t t = clock();
		booble_sort(array, i);
		t = clock() - t; //tempo final - tempo inicial
		imprime(array,i); //Impressao em arquivo
		printf("Tempo de ordenacao Booble_sort: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //Em milisegundos
	}else if(strcmp(argv[1],"-c") == 0){//So funciona para a primeira ocorrencia
		int j, achou = buscabinaria(i, array, querry);
		if(achou<=contexto){
			for(j=achou;j<contexto+strlen(querry);j++){
				printf("%c",texto[j]);
			}
		}else{
			for(j=achou-contexto;j<contexto+strlen(querry);j++){
				printf("%c",texto[j]);
			}
		}
	}

	destroy_string(string);
	destroy_suf_array(array,i);
	return 0;
}

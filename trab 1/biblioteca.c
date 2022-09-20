#include "biblioteca.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

//Função que restaura o vetor a sua forma original
void zeraVetor(int *vetOriginal, int* vetAuxiliar, int tam){
    for(int cont=0;cont<tam;cont++){//Preenchimento do vetor aux com a ordem inicial
		vetAuxiliar[cont]=vetOriginal[cont];
	}
}

void zeraCompTroca(long int* comp, long int* troca){
    *comp = 0;
    *troca = 0;
}
//Funcao Quick Sort
void quick_sort(int *vet, int esquerda, int direita, long int* comp, long int* troca) {
    int i, j, x, y;
     
    i = esquerda;
    j = direita;
    x = vet[(esquerda + direita) / 2];
     
    while(i <= j) {
        while(vet[i] < x && i < direita) {
            *comp+=1;
            i++;
        }
        while(vet[j] > x && j > esquerda) {
            *comp+=1;
            j--;
        }
        if(i <= j) {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
            *troca+=1;
        }
    }
    //Chamadas recursivas da funcao ate estar ordenado
    if(j > esquerda) {
        quick_sort(vet, esquerda, j, comp, troca);
    }
    if(i < direita) {
        quick_sort(vet, i, direita, comp, troca);
    }
}

//Funcao Shell Sort
void shell_sort(int *vet, int tam, int T, long int* comp, long int* troca){
 int i , j , x;
 int gap = 1;
 *troca = 0;
 *comp = 0;
  
 do {
  gap = 3*gap+1;
 } while(gap < tam);
  
 do {
  gap /= 3;
  for(i = gap; i < tam; i++) {
      if (gap == 1 && i == T + 1)
                return;
   x = vet[i];
   j = i - gap;
    
   while (j >= 0 && x < vet[j]) {
        *comp+=1;
        *troca+=1;
        vet[j + gap] = vet[j];
        j -= gap;
   }
   vet[j + gap] = x;
  }
 }while(gap > 1);
}

//Funcao que cria a arvore para a heap_sort
void cria_heap(int *vet, int ini, int fim, long int* comp, long int* troca){
	int aux = vet[ini], i = ini*2+1;
	while(i<=fim){
		if(i < fim){
			if(vet[i] < vet[i + 1]){
                *comp+=1;
				i++;
			}	
		}
		if(aux < vet[i]){
			vet[ini] = vet[i];
			ini = i;
			i = 2* ini + 1;
            *comp+=1;
		}else{
			i = fim + 1;
		}
		
	}
    *troca+=1;

	vet[ini] = aux;
}

//Funcao Heap Sort
void heap_sort(int *vet, int tam, int T, long int* comp, long int* troca){
	int i, aux, meio_vet=(tam-1)/2;
    *troca = 0;
    *comp = 0;

	for(i=meio_vet; i>=0; i--){
		cria_heap(vet,i,tam-1, comp, troca);
	}
	for(i = tam-1; i >=0; i--){
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
        *troca+=1;

		cria_heap(vet, 0, i-1, comp, troca);
	}
}

//Funcao selection_sort
void selection_sort(int *vet, int tam, int T, long int* comp, long int* troca) { 
  int i, j, min, aux;
  *troca = 0;
  *comp = 0;

  for (i = 0; i < T; i++) 
  {
    
     min = i; //Armazena a posição de análise
     for (j = (i+1); j < tam; j++) { //Verifica a existência de números maiores ao decorrer do vetor
         *comp+=1;
       if(vet[j] < vet[min]) 
         min = j;
     }
     if (i != min) { //Caso ache um número menor que o original da posição em análise é realizada a troca
        *troca+=1;
       aux = vet[i];
       vet[i] = vet[min];
       vet[min] = aux;
     }
  }
}

//Funcao insertion_sort
void insertion_sort(int *vet, int tam, int T, long int* comp, long int* troca){
    int i, j, aux;
    *troca = 0;
    *comp = 0;

    for (i = 1; i < T; i++) {
        aux = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j = j - 1;
            *troca+=1;
        }
        vet[j + 1] = aux;
        *comp+=1;
    }
}

//Função impresão
void imprime(int* vet, int tam, char* endereco, long int* comp, long int* troca, char saida, int top, double time, char ord){
    char ordenacao[10];
  if(saida == '1'){
    for(int i = 0 ; i < top; i++){
        printf("%d\n", vet[i]);
    }

    printf("\n");
    
    }
    
    if(saida == '2'){
        printf("Tempo do CPU:   %.10f segundos.\n", time);
        printf("Comparacoes:    %ld\n", *comp);
        printf("Trocas:    %ld\n\n", *troca);
    }
    
    if(saida == '3'){
        switch (ord)
        {
        case 's':
            strcpy(ordenacao,"Selection");
            imprimeTudo(ordenacao, endereco, tam, top, comp, troca, time);
            break;
        case 'i':
            strcpy(ordenacao,"Isertion");
            imprimeTudo(ordenacao, endereco, tam, top, comp, troca, time);
            break;
        case 'e':
            strcpy(ordenacao,"Shell");
            imprimeTudo(ordenacao, endereco, tam, top, comp, troca, time);
            break;
        case 'q':
            strcpy(ordenacao,"Quick");
            imprimeTudo(ordenacao, endereco, tam, top, comp, troca, time);
            break;
        case 'h':
            strcpy(ordenacao,"Heap");
            imprimeTudo(ordenacao, endereco, tam, top, comp, troca, time);
            break;
        default:
            break;
        }
        
    }

}

//Fução que imprime as estatisticas completas
void imprimeTudo(char* ord, char* endereco, int tam, int top, long int* comp, long int* troca, double time){
    printf("Algoritmo: %s\nArquivo: %s\nTamanho: %d\nT(top): %d\nComparacoes: %ld\nTrocas: %ld\nTempo(s): %f\n\n", ord, endereco, tam, top, *comp, *troca, time);
}

void todos(int *vet, int tam, int T, long int* comp, long int* troca, char* endereco){
    clock_t t;
	double time;
    int vet_aux[tam];

    zeraVetor(vet, vet_aux, tam);
    zeraCompTroca(comp, troca);

    //--insertion--
    t = clock(); // armazena tempo 
    insertion_sort(vet_aux, tam, T, comp, troca);
    t = clock() - t; // tempo final - tempo inicial
    time = ((double)t)/((clock_t)(1000000)); //Converte tempo em segundos

    imprime(vet_aux, tam, endereco, comp, troca, '3', T, time, 'i');

    zeraVetor(vet, vet_aux, tam);
    zeraCompTroca(comp, troca);

    //--selection--
    t = clock(); // armazena tempo 
    selection_sort(vet_aux, tam, T, comp, troca);
    t = clock() - t; // tempo final - tempo inicial
    time = ((double)t)/((clock_t)(1000000)); //Converte tempo em segundos

    imprime(vet_aux, tam, endereco, comp, troca, '3', T, time, 's');

    zeraVetor(vet, vet_aux, tam);
    zeraCompTroca(comp, troca);

    //--shel-----
    t = clock(); // armazena tempo 
    shell_sort(vet_aux, tam, T, comp, troca);
    t = clock() - t; // tempo final - tempo inicial
    time = ((double)t)/((clock_t)(1000000)); //Converte tempo em segundos

    imprime(vet_aux, tam, endereco, comp, troca, '3', T, time, 'e');
    
    zeraVetor(vet, vet_aux, tam);
    zeraCompTroca(comp, troca);

    //--heap------
    t = clock(); // armazena tempo 
    heap_sort(vet_aux,tam, T, comp, troca);
    t = clock() - t; // tempo final - tempo inicial
    time = ((double)t)/((clock_t)(1000000)); //Converte tempo em segundos

    imprime(vet_aux, tam,endereco, comp, troca, '3', T, time, 'h');

    zeraVetor(vet, vet_aux, tam);
    zeraCompTroca(comp, troca);

    
    //--quick----
    t = clock(); // armazena tempo  
    quick_sort(vet_aux,0,tam-1, comp, troca);
    t = clock() - t; // tempo final - tempo inicial
    time = ((double)t)/((clock_t)(1000000)); //Converte tempo em segundos

    imprime(vet_aux, tam, endereco, comp, troca, '3', T, time, 'q');

}

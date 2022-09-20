#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

//Declaracao das funcoes
void quick_sort(int *vet, int esquerda, int direita, long int* comp, long int* troca);

void shell_sort(int *vet, int tam, int T, long int* comp, long int* troca);

void heap_sort(int *vet, int tam, int T, long int* comp, long int* troca);

void selection_sort(int *vet, int tam, int T, long int* comp, long int* troca);

void insertion_sort(int *vet, int tam, int T,long int* comp, long int* troca);

void imprime(int* vet, int tam, char* endereco, long int* comp, long int* troca, char saida, int top, double time, char ord);

void imprimeTudo(char* ord, char* endereco, int tam, int top, long int* comp, long int* troca, double time);

void todos(int *vet, int tam, int T, long int* comp, long int* troca, char* endereco);

#endif //BIBLIOTECA_H

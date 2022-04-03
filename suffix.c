#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "suffix.h"
#include "str.h"


//Cria a struct Sufixx
Suffix* create_suffix(String *s, int index){
    Suffix* suf = malloc(sizeof *suf);
    suf->index = index;
    suf->s = create_string(&s->c[index]);
    return suf;
}


//Ha um bug, so funciona na primeira metade com o teste abra.txt
//Esta versao retorna apenas a primeira ocorrencia
/*int buscabinaria(int n, Suffix** array, char* querry){
    int ini = 0;
    int fim = n-1;
    int meio;
    char *aux = malloc(sizeof(char)*strlen(querry));//String auxiliar pra busca binária
    int len =(int)strlen(querry);
    while(ini <= fim){
        int i=0;
        meio = (ini + fim)/2;
        for(i=0;i<len;i++){
            aux[i]=array[meio]->s->c[i];
        }
        if(strcmp(querry,aux)){
            fim = meio -1;
        }else if((strcmp(querry,aux))*-1){
            ini = meio + 1;
        }else return meio;
    }return -1;//indicacao que nao foi encontrado
}
*/

char * cortaString(int n, char* string){
    char *novaString = malloc(n * sizeof(char));
    int i;
    for(i=0; i<n; i++){
        novaString[i] = string[i]; 
    }
    novaString[n] = '\0';
    return novaString;
}


int buscabinaria(int n, Suffix** array, char* querry, int * posicao){
    int ini=-1;
    int fim=n-1;
    int meio, cmp;
    char * aux; 
    while (ini <= fim)
    {
        meio = (ini+fim)/2;
        aux = cortaString(strlen(querry),array[meio]->s->c);
        cmp=strcmp(querry,aux);
        if (cmp<0)
            fim = meio-1;
        else if (cmp>0)
            ini = meio+1;
        else{
            //printf("%d\n", &posicao);
            *posicao = meio; //nao funciona, impediu imprimir varias ocorrencias
            return array[meio]->index;
        }
        free(aux);
    }
    return -1;
}

void buuble_sort(Suffix **array, int n){
    Suffix *aux;
    int i, j, comp;
    for(i = 0 ;i < n; i++){
        for(j=i+1;j<n-1;j++){
            comp = strcmp(array[i]->s->c,array[j]->s->c);
            if(comp > 0){
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

//Libera a memoria ocupada pelo sufixo
void destroy_suffix(Suffix *suf){
    destroy_string(suf->s);
    free(suf);
}

//Cria o array de String
Suffix** create_suf_array(String *text, int N){
    Suffix** array = malloc(N * sizeof(Suffix));
    for(int i = 0;i<N;i++){
        array[i] = create_suffix(text,i); 
    }
    return array;
}


//Libera a memoria do vetor 
void destroy_suf_array(Suffix* *a, int N){
    for(int i;i<N;i++){
        destroy_suffix(a[i]);
    }
    free(a);
}

int compare_suffix(const void *s1, const void *s2){
    Suffix* a = (Suffix*)s1;
    Suffix* b = (Suffix*)s2;
    //return compare(a->s, b->s);
    return strcmp(a->s->c,b->s->c);
}

void imprime(Suffix** array, int tamanho){
    int result;
    FILE *s;
    s = fopen("Saida.txt","w");
	if(s == NULL){
		printf("Erro na abertura do arquivo de saida");
        return;
	}
    for(int i = 0; i<tamanho; i++){
        result = fprintf(s,"%s",array[i]->s->c);
        fprintf(s,"\n");
        printf("%s \n",array[i]->s->c);
        if(result == EOF){
            printf("Erro na gravacao");
            return;
        }
    }
	
	fclose(s);
}
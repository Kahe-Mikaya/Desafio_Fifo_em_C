#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Bloco
typedef struct bloco {
    int conteudo;
    struct bloco *proximo;
} Bloco;

// Definição da estrutura Fila
typedef struct fila {
    Bloco *primeiro;
    Bloco *ultimo; // Adiciona um ponteiro para o último elemento
    int sizeAtual;
    int sizeTotal;
    int falhas;
} Fila;

// Função para criar uma fila
Fila criarFila(int tamanho) {
    Fila f;
    f.falhas = 0;
    f.sizeTotal = tamanho;
    f.sizeAtual = 0;
    f.primeiro = NULL;
    f.ultimo = NULL;
    return f;
}

// Função para verificar se a fila está vazia
int FilaVazia(Fila *f) {
    return f->sizeAtual == 0;
}

// Função para verificar se a fila está cheia
int FilaCheia(Fila *f) {
    return f->sizeAtual >= f->sizeTotal;
}

// Função para buscar um elemento na fila
Bloco *BuscarElemento(Fila *f, int numero) {
    Bloco *atual = f->primeiro;
    while (atual != NULL) {
        if (atual->conteudo == numero) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Função para adicionar um elemento à fila
int adicionarElemento(Fila *f, int numero) {
    if (BuscarElemento(f, numero) != NULL) {
        return 0; // Elemento já existe na fila
    }

    

    Bloco *novo = (Bloco *)malloc(sizeof(Bloco));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return 0; // Falha na alocação de memória
    }

    novo->conteudo = numero;
    novo->proximo = NULL;

    if (FilaVazia(f)) {
        f->primeiro = novo;
        f->ultimo = novo;
    } else {
        f->ultimo->proximo = novo;
        f->ultimo = novo;
        if (FilaCheia(f)) {
            f->primeiro = f->primeiro->proximo;
            
        }
    }
    
    f->sizeAtual++;
    return 1; // Elemento adicionado com sucesso
}

// Função para mostrar os elementos da fila
void mostrarFila(Fila *f) {
    Bloco *aux = f->primeiro;
    printf("fila [");
    while (aux != NULL) {
        printf("%d", aux->conteudo);
        aux = aux->proximo;
        if (aux != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("Total de falhas: %d \n",f->sizeAtual);
}

void preencherFilaComVetor(Fila *f, int vetor[],int tamanho){

    int indice;
    for(indice = 0; indice<tamanho;indice++){
        adicionarElemento(f,vetor[indice]);
    }
    
}
void imprimirVetor(int vetor[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Função principal
int main() {

  


    printf("DESAFIO 1 \n");
    Fila f = criarFila(3);
    int vetor[] ={2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    printf("\nEntrada\nsequencia de paginas: ");
    imprimirVetor(vetor,tamanho);
    printf("numero de molduras: %d \n",3);
    printf("\nSaida: \n");
    preencherFilaComVetor(&f,vetor,tamanho);
    mostrarFila(&f);
    
    printf("\nDESAFIO 2 \n");
    Fila f2 = criarFila(4);
    int vetor2[] = {5, 6, 7, 8, 5, 6, 8, 9, 7, 6};
    int tamanho2 = sizeof(vetor2) / sizeof(vetor2[0]);
    printf("\nEntrada \nSequência de páginas: ");
    imprimirVetor(vetor2, tamanho2);
    printf("Número de molduras: %d\n", 4);
    printf("\nSaída:\n");
    preencherFilaComVetor(&f2, vetor2, tamanho2);
    mostrarFila(&f2);
    
    printf("\nDESAFIO 3 \n");
    Fila f3 = criarFila(3);
    int vetor3[] = {0, 2, 1, 6, 4, 0, 1, 0, 2, 1, 4};
    int tamanho3 = sizeof(vetor3) / sizeof(vetor3[0]);
    printf("\nEntrada\nSequência de páginas: ");
    imprimirVetor(vetor3, tamanho3);
    printf("Número de molduras: %d\n", 3);
    printf("\nSaída:\n");
    preencherFilaComVetor(&f3, vetor3, tamanho3);
    mostrarFila(&f3);
    
    printf("\nDESAFIO 4 \n");
    Fila f4 = criarFila(4);
    int vetor4[] = {9, 3, 4, 2, 5, 6, 4, 9, 7, 1, 3};
    int tamanho4 = sizeof(vetor4) / sizeof(vetor4[0]);
    printf("\nEntrada \nSequência de páginas: ");
    imprimirVetor(vetor4, tamanho4);
    printf("Número de molduras: %d\n", 4);
    printf("\nSaída:\n");
    preencherFilaComVetor(&f4, vetor4, tamanho4);
    mostrarFila(&f4);
    
    printf("\nDESAFIO 5 \n");
    Fila f5 = criarFila(3);
    int vetor5[] = {0, 2, 1, 6, 4, 0, 1, 0, 2, 1, 4};
    int tamanho5 = sizeof(vetor5) / sizeof(vetor5[0]);
    printf("\nEntrada \nSequência de páginas: ");
    imprimirVetor(vetor5, tamanho5);
    printf("Número de molduras: %d\n", 3);
    printf("\nSaída:\n");
    preencherFilaComVetor(&f5, vetor5, tamanho5);
    mostrarFila(&f5);
    
    printf("\nDESAFIO 6 \n");
    Fila f6 = criarFila(2);
    int vetor6[] = {8, 5, 7, 5, 4, 6, 8, 6, 1, 4, 8, 7};
    int tamanho6 = sizeof(vetor6) / sizeof(vetor6[0]);
    printf("\nEntrada\nSequência de páginas: ");
    imprimirVetor(vetor6, tamanho6);
    printf("Número de molduras: %d\n", 2);
    printf("\nSaída:\n");
    preencherFilaComVetor(&f6, vetor6, tamanho6);
    mostrarFila(&f6);


    return 0;
}

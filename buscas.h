#ifndef buscas_h
#define buscas_h
#include "library.h"

int tempo, ciclo, conexo = 0;
#define BRANCO 1
#define CINZA  2
#define PRETO  3

void dfs(grafo_t *grafo);
void dfs_visit(no_t* no);
void mostraGrafoDFS(grafo_t * grafo);

void dfs(grafo_t *grafo){
    int i;

    for (i = 0; i < grafo->num_vertices; i++){
        no_t *Primeiro = grafo->VETOR_list_adj[i].prox;

        while (Primeiro){
            Primeiro->cor = BRANCO;
            Primeiro->pred = Primeiro;

            Primeiro = Primeiro->prox;
        }
    }

    tempo = 0;
    
    for (i = 0; i < grafo->num_vertices; i++){
        no_t *Primeiro = grafo->VETOR_list_adj[i].prox;

        while (Primeiro){
            if (Primeiro->cor == BRANCO){
                dfs_visit(Primeiro);
                conexo++;
            }
            Primeiro = Primeiro->prox;
        }
    }
}

void dfs_visit(no_t* no){
    int i;
    no->cor = CINZA;
    tempo++;
    no->d = tempo;
    no_t *Primeiro = no->prox;
    
    while (Primeiro){
        if (Primeiro->cor == BRANCO){
            Primeiro->pred = no;
            dfs_visit(Primeiro);
        }else{
            ciclo++;
        }

        Primeiro = Primeiro->prox;
    }
    no->cor = PRETO;
    tempo++;
    no->f = tempo;
}

void mostraGrafoDFS(grafo_t * grafo){
    int i;
    int cont = 0;
    
    printf("\nQuantidade de ciclos: %d\n", ciclo);
    printf("É conexo (acima de 0 é não conexo): %d\n\n", conexo);

    for (i = 0; i < grafo->num_vertices; i++){
        no_t *Primeiro = grafo->VETOR_list_adj[i].prox;        
        while (Primeiro){
            cont++;
            if (Primeiro->f < grafo->num_vertices * 2 + 1) {
                printf("Vértice: %d. ", Primeiro->vertice);
                printf("Cor: %d. ", Primeiro->cor);
                printf("Predecessor: %d. ", Primeiro->pred->vertice);
                printf("Tempo de entrada: %d. ", Primeiro->d);
                printf("Tempo de saída: %d. \n", Primeiro->f);
                printf("\n");
            }
        Primeiro = Primeiro->prox;
        }        
    }
}

#endif
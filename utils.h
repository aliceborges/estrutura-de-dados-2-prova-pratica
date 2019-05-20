#define utils_h

typedef struct no{
    int vertice; 
    struct  no *prox;
}no_t;

typedef struct grafo{
    int num_vertices;
    no_t *VETOR_list_adj;
}grafo_t;

typedef struct digraph{
    int numVertice;
    int **matriz_adj;
}tipo_digrafo;

no_t *criaNO(int v);
grafo_t *criaGRAFO(int n);
tipo_digrafo *criaDIGRAFO (int num_vertices);
int **criaMatriz (int total_linha, int total_coluna, int valor);
void addARESTA(grafo_t *grafo, int origem, int dest);
void addArestaDIGRAFO(grafo_t *grafo, int origem, int dest);
void insere_arco_digrafo (tipo_digrafo *digrafo, int origem, int destino);
void insere_arco_GRAFO(tipo_digrafo *digrafo, int origem, int destino);

grafo_t *criaGRAFO(int n){
    int i;
    grafo_t *grafo = (grafo_t*)malloc(sizeof(grafo_t));
    if(!grafo){
        printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMÓRIA PARA O GRAFO \n SAINDO... \n");
        exit(EXIT_FAILURE);
    }

    grafo->num_vertices = n;

    grafo->VETOR_list_adj = (no_t*)malloc(n * sizeof(no_t));
    if(!grafo->VETOR_list_adj){
        printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMÓRIA PARA O VETOR DE LISTA ADJACENTE \n SAINDO... \n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
        grafo->VETOR_list_adj[i].prox = NULL;
    
    return grafo;
}

tipo_digrafo *criaDIGRAFO (int num_vertices){
    tipo_digrafo *G = malloc(sizeof(tipo_digrafo));
    G->numVertice = num_vertices;
    G->matriz_adj = criaMatriz(num_vertices, num_vertices, 0);

    return G;
}

void addARESTA(grafo_t *grafo, int origem, int dest){
    no_t *novoNO = criaNO(dest);
    novoNO->prox = grafo->VETOR_list_adj[origem].prox;
    grafo->VETOR_list_adj[origem].prox = novoNO;
}


void addArestaDIGRAFO(grafo_t *grafo, int origem, int dest){
    no_t *novoNO = criaNO(dest);
    novoNO->prox = grafo->VETOR_list_adj[origem].prox;
    grafo->VETOR_list_adj[origem].prox = novoNO;

    novoNO = criaNO(origem);
    novoNO->prox = grafo->VETOR_list_adj[dest].prox;
    grafo->VETOR_list_adj[dest].prox = novoNO;
}

int **criaMatriz (int total_linha, int total_coluna, int valor){
    int linha, coluna;
    int **matriz = (int **)malloc(total_coluna * sizeof(int *));

    for (linha = 0; linha < total_linha; linha++)
        matriz[linha] = (int *)malloc(total_coluna * sizeof(int));

    for (linha = 0; linha < total_linha; linha++)
        matriz[linha][coluna] = valor;

    return matriz;
}

void insere_arco_digrafo (tipo_digrafo *digrafo, int origem, int destino){
    if (digrafo->matriz_adj[origem][destino] == 0){
        digrafo->matriz_adj[origem][destino] = 1;
    }
}

void insere_arco_GRAFO(tipo_digrafo *digrafo, int origem, int destino){
    insere_arco_digrafo(digrafo, origem, destino);
    insere_arco_digrafo(digrafo, destino, origem);
}

no_t *criaNO(int v){
    no_t *novoNO = (no_t*)malloc(sizeof(no_t));
    if(!novoNO){
        printf("[ERRO FATAL]: IMPOSSIVEL ALOCAR MEMORIA PARA UM NOVO NO \n SAINDO... \n");
        exit(EXIT_FAILURE);
    }

    novoNO->vertice = v;
    novoNO->prox = NULL;

    return novoNO;
}

void mostraGRAFO(grafo_t * grafo){
    int i;
    for (i = 0; i < grafo->num_vertices; i++){
        no_t *Primeiro = grafo->VETOR_list_adj[i].prox;
        printf("\n%d -> ", i);
        while (Primeiro){
            printf(" %d", Primeiro->vertice);
            if (Primeiro->prox)
                printf(" -> ");

            Primeiro = Primeiro->prox;
        }

        printf("\n");
    }
}

void mostra_digrafo (tipo_digrafo *digrafo){
    int origem, destino, i;
    printf("\n MOSTRA MATRIZ DE ADJACÊNCIA - DIGRAFO \n");

    printf("  ");
    for (i = 0; i < digrafo->numVertice; i++){
        printf("%d ", i);
    }
    printf("\n");

    for (origem = 0; origem < digrafo->numVertice; origem++){
        printf("%d", origem);
        for (destino = 0; destino < digrafo->numVertice; destino++){
            printf(" %d", digrafo->matriz_adj[origem][destino]);
        }
        printf("\n");
    }
}

void destroiGRAFO(grafo_t* grafo){
     
     int v;
     
     if(grafo){
         if(grafo->VETOR_list_adj){
             for(v = 0; v < grafo->num_vertices; v++){
                 no_t *Primeiro = grafo->VETOR_list_adj[v].prox;
                 while(Primeiro){
                     no_t *tmp = Primeiro;
                     Primeiro = Primeiro->prox;
                     free(tmp);
                 }
             }

             free(grafo->VETOR_list_adj);
         }
         free(grafo);
     }
}

void remove_arco_digrafo (tipo_digrafo *digrafo, int origem, int destino){
    if (digrafo->matriz_adj[origem][destino] == 1){
        digrafo->matriz_adj[origem][destino] = 0;
    }
}

void converte_matriz_lista(tipo_digrafo *digrafo, grafo_t *novo_grafo) {   
    int origem, destino;

    for (origem = 0; origem < digrafo->numVertice; origem++) {
        for (destino = 0; destino < digrafo->numVertice; destino++) {
            if (digrafo->matriz_adj[origem][destino] != 0)
                addARESTA(novo_grafo, origem, destino);
        }
    }
}

void converte_lista_matriz(grafo_t *grafo, tipo_digrafo* digrafo) {
    int i;
    for (i = 0; i < grafo->num_vertices; i++) {
        no_t *Primeiro = grafo->VETOR_list_adj[i].prox;
        while (Primeiro) {
            insere_arco_digrafo(digrafo, i, Primeiro->vertice);
            Primeiro = Primeiro->prox;
        }
    }
}
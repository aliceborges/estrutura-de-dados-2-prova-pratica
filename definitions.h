#ifndef definitions_h
#define definitions_h

typedef struct no{
    int vertice, cor, d, f; // D = tempo de entrada; F = tempo de saída
    struct no *prox, *pred; // PREDECESSOR - pi
} no_t;

typedef struct grafo{
    int num_vertices;
    no_t *VETOR_list_adj;
} grafo_t;

typedef struct digrafo{
    int numVertice;
    int **matriz_adj;
} tipo_digrafo;

#endif

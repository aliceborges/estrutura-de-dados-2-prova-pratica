#define q1_h
#include "library.h"

// QUESTÃO 1
// Escreva um programa que receba, como entrada, uma matriz de adjacência de um
// grafo e produza, como saída, uma lista de adjacência (1.0).

int q1(){
    float i1, resultado1;
    printf("===========================================\n");
    printf("QUESTÃO 1\n");
    
    printf("Matriz adicionada: \n");
    tipo_digrafo *digrafo = criaDIGRAFO(5);
    insere_arco_digrafo(digrafo, 0, 1);
    insere_arco_digrafo(digrafo, 0, 1);
    insere_arco_digrafo(digrafo, 0, 4);
    insere_arco_digrafo(digrafo, 1, 2);
    insere_arco_digrafo(digrafo, 1, 3);
    insere_arco_digrafo(digrafo, 1, 4);
    insere_arco_digrafo(digrafo, 2, 3);
    insere_arco_digrafo(digrafo, 3, 4);
    mostra_digrafo(digrafo);

    printf("Convertida para lista de adjacência: \n");
    grafo_t *dir_grafo = criaGRAFO(5);
    converte_matriz_lista(digrafo, dir_grafo);
    mostraGRAFO(dir_grafo);

    return 0;
}

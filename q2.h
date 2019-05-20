#define q2_h
#include "library.h"

// QUESTÃO 2
// Escreva um programa que receba, como entrada, uma lista de adjacência de um grafo
// e produza, como saída, uma matriz de adjacência (1.0).

int q2(){
    float i1, resultado1;
    printf("===========================================\n");
    printf("QUESTÃO 2\n");
    
    printf("Lista de adjacência adicionada: \n");
    grafo_t * dir_grafo2 = criaGRAFO(5);
    addArestaDIGRAFO(dir_grafo2, 0, 3);
    addArestaDIGRAFO(dir_grafo2, 0, 2);
    addArestaDIGRAFO(dir_grafo2, 1, 4);
    addArestaDIGRAFO(dir_grafo2, 1, 2);
    addArestaDIGRAFO(dir_grafo2, 1, 3);
    addArestaDIGRAFO(dir_grafo2, 2, 4);
    addArestaDIGRAFO(dir_grafo2, 3, 1);
    mostraGRAFO(dir_grafo2);

    printf("Convertida para matriz: \n");
    tipo_digrafo *digrafo2 = criaDIGRAFO(5);
    converte_lista_matriz(dir_grafo2, digrafo2);
    mostra_digrafo(digrafo2);

    return 0;
}

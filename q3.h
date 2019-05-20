#ifndef q3_q4_h
#define q3_q4_h
#include "library.h"
#include "grafo.h"
#include "buscas.h"

// QUESTÃO 3
// A partir de dados de um grafo, lidos de uma lista de adjacência, escreva um programa
// que determine se o grafo é cíclico ou acíclico. Caso seja cíclico, conte e exiba a
// quantidade de ciclos do grafo (1.0).

int q3_q4(){
    float i1, resultado1;
    printf("===========================================\n");
    printf("QUESTÃO 3 e 4\n");
    
    printf("Lista de adjacência adicionada: \n");
    grafo_t * dir_grafo3 = criaGRAFO(5);
    addARESTA(dir_grafo3, 1, 2);
    addARESTA(dir_grafo3, 1, 3);
    addARESTA(dir_grafo3, 1, 4);
    addARESTA(dir_grafo3, 2, 3);
    addARESTA(dir_grafo3, 2, 4);
    addARESTA(dir_grafo3, 3, 1);
    addARESTA(dir_grafo3, 4, 1);
    // mostraGrafo(dir_grafo3);

    dfs(dir_grafo3);
    mostraGrafoDFS(dir_grafo3);
    destroiGRAFO(dir_grafo3);

    return 0;
}

#endif
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <cstdint>
#include <stdint.h>
#include <array>
#include <iomanip>
#include <random>
#include <ctime>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>



//É necessário declarar uma estrutura de dados contida na matriz para termos métricas de armazenamento e assim
//usar alocação dinâmica para criar e depois percorrer a matriz:

//Estrutura de dados dos elementos da matriz:
struct MatrixElement
{
    unsigned short int Element;
};


struct Coordinate {
    unsigned short int i, j, Value;
};

#endif


//referências:  https://youtu.be/Gp2m8ZuXoPg?t=1343 , 
//              https://github.com/mpiress/GenerateDataToMatrix/blob/main/src/mat.h

//Descoberta interessante: Não se pode dar malloc dentro de um struct, mas por quê?
//            tentativa: Pois a estrutura ainda não foi alocada na memória e malloc
//            requisita uma instrução de alocação de memória. Portanto não se pode espaço
//            de uma estrutura que ainda não tem seu tamanho de alocação pré-definido, acredito
//            que isso aconteça pelo fato de que é necessário ter uma estrutura completamente declada
//            para que ela seja depois disso alocada na memória.

//Proposta de Melhoria: Criar um jeito de ter um número aleatório no lugar de TAM sem ter problemas
// com alocação de memória, de forma que esse número esteja por exemplo pré-processado em um arquivo.


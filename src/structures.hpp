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

using namespace std;


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

unsigned short int RandomGenerator(unsigned short int a, unsigned short int b);


unsigned short int SizeRecon();


void MatrixScanner(unsigned short int size,MatrixElement *Matrix);


void CoordinateDefinition(unsigned short int *i,unsigned short int *j);


unsigned short int* RoadMapDefiner(vector<unsigned short int> Steps,unsigned short int HowManySteps);

void RoadMapViewer(unsigned short int *iRoute,unsigned short int *jRoute, unsigned short int HowManySteps, MatrixElement *FinalMatrix,unsigned short int size);

void CreatingCoordinates(unsigned short int size,unsigned short int i,unsigned short int j, bool *S, bool *SE, bool *SW, bool *W, bool *E);

void FivePossibleWays(MatrixElement *FinalMatrix, unsigned short int *i,unsigned short *j,unsigned short int size, unsigned short int *IndexHigher, unsigned short *lasti, unsigned short *lastj);

void SouthEastPossibleWays(MatrixElement *FinalMatrix, unsigned short int *i,unsigned short *j,unsigned short int size, unsigned short int *IndexHigher, unsigned short *lasti, unsigned short *lastj);

void SouthWestPossibleWays(MatrixElement *FinalMatrix, unsigned short int *i,unsigned short *j,unsigned short int size, unsigned short int *IndexHigher, unsigned short *lasti, unsigned short *lastj);

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


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.hpp"

using namespace std;


/// @brief GEra um número aleatório entre 2 valores
/// @param Higher Maior valor possível gerado
/// @param Lower Menor valor possível gerdao
/// @return Valor aleatório entre Higher e Lower
unsigned short int RandomGenerator(unsigned short int Higher, unsigned short int Lower)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(Higher, Lower);
    return dis(gen);
}

/// @brief Lê a primeira linha do arquivo input.data e retorna uma variável que representa o tamanho das matrizes contidas nesse arquivo
/// @return O tamanho das matrizes à serem lidas
unsigned short int SizeRecon()
{
    unsigned short int ArrayArea = 0;
    FILE *LocalPointer;
    LocalPointer = fopen("./dataset/input.data", "r");
    fscanf(LocalPointer, "%hu", &ArrayArea);
    fclose(LocalPointer);
    return ArrayArea;
}

/// @brief Lê uma matriz passada como argumento do tamanho passado por argumento
/// @param size 
/// @param Matrix 
void MatrixScanner(unsigned short int size,MatrixElement *Matrix)
{
    unsigned short int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            //cout<<((*Matrix[i][j]).Element);
            cout<<(*((Matrix+i*size)+j)).Element<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n\n\n";
}

/// @brief //Pede para que o usuário declare duas cordenadas que são armazenadas em i e j
/// @param i Coordenada de deslocamento em linhas sendo 0 o menor valor possível
/// @param j Coordenada de deslocamento em colunas sendo 0 o menor valor possível
void CoordinateDefinition(unsigned short int *i,unsigned short int *j)
{
    cout<<"Insert a line (i): ";
    cin>>*i;
    cout<<"Insert a column (j): ";
    cin>>*j;

    cout<<"\n";
}

/// @brief //Recebe um vector com valores dos passos dados e retorna um vetor de memória alocada com base no tamanho do vector, contendo os passos do vector:
/// @param Steps Vector que contem coordenadas em i ou em j dos passos realizados
/// @param HowManySteps Número de passos dados na busca realizada em uma matriz
/// @return Um vetor com as mesmas variáveis do vector
unsigned short int* RoadMapDefiner(vector<unsigned short int> Steps,unsigned short int HowManySteps)
{
    unsigned short int Counter=0;
    unsigned short int *Route = (unsigned short int*)malloc(sizeof(unsigned short int)*(HowManySteps+10));

    for(auto index=Steps.begin();index!=Steps.end();index++)
    {
        Route[Counter] = *index;
        Counter+=1;
    }
    
    return Route;
}

/// @brief Mostra a ordem e local dos passos realizados por uma busca em uma matriz:
/// @param iRoute Um vetor com coordenadas de deslocamento em i
/// @param jRoute Um vetor com coordenadas de deslocamento j
/// @param size Tamanho da matriz onde a busca foi feita
/// @param HowManySteps Número de passos dados na busca realizada em uma matriz
void MapOfTheJourney(unsigned short int *iRoute,unsigned short int *jRoute,unsigned short int size, unsigned short int HowManySteps)
{
   unsigned short int BinaryMatrix[size][size];
    
    for(unsigned short int idxi=0;idxi<size;idxi++)
    {
        for(unsigned short int idxj=0;idxj<size;idxj++)
        {
            BinaryMatrix[idxi][idxj]=999;
        } 
    }

    for(int index = 0;index<HowManySteps;index++)
    {
        unsigned short int i = iRoute[index];
        unsigned short int j = jRoute[index];

        BinaryMatrix[i][j] = index;
    }

    for(unsigned short int column = 0;column<size;column++)
    {   
        if(column == 0)
            cout<<"i / j\t|"<<column;
        else 
            cout<<"|\t|"<<column;

    }
    cout<<"\n";

    for(unsigned short int idxi=0;idxi<size;idxi++)
    {
        cout<<"\n|"<<idxi<<"|\t";
        for(unsigned short int idxj=0;idxj<size;idxj++)
        {
            if(idxj==0)
                cout<<BinaryMatrix[idxi][idxj];
                
            
            else
                cout<<"\t"<<BinaryMatrix[idxi][idxj];
        }
        cout<<"\n------------------------------------------------------------------------------------";
    }
}

/// @brief Mostra os passos da busca local com suas coordenadas e valores e adiciona os dados locais à uma variável de soma global:
/// @param iRoute Um vetor com coordenadas de deslocamento em i
/// @param jRoute Um vetor com coordenadas de deslocamento j
/// @param FinalMatrix Matriz onde a busca está sendo realizada
/// @param HowManySteps Número de passos dados na busca em FinalMatrix
/// @param size Tamanho da matriz
/// @param GlobalSum Soma de todos os valores encontrados na busca realizada em FinalMatrix
void RoadMapViewer(unsigned short int *iRoute,unsigned short int *jRoute, unsigned short int HowManySteps, MatrixElement *FinalMatrix,unsigned short int size, unsigned int *GlobalSum)
{
    unsigned short int LocalSumOfSteps = 0;

    cout<<"A trajetória realizada com as especificações de pesquisa na matriz foram:"<<"\n";
    cout<<"   Passos         [i]   [j]   [Valor]"<<"\n";
    cout<<"-----------------------------------------\n";


    for(unsigned short int index=0;index<HowManySteps;index++)
    {
        cout<<index<<"º passo";
        cout<<"\t | "<<iRoute[index]<<" |"<<" | "<<jRoute[index]<<" | "<< " | "<<(*(FinalMatrix+iRoute[index]*size+jRoute[index])).Element<<" | \n";
        LocalSumOfSteps+=(*(FinalMatrix+iRoute[index]*size+jRoute[index])).Element;
    }
    
    cout<<"-----------------------------------------\n";
    cout<<"A soma local foi:\t"<<LocalSumOfSteps<<"\n\n";

    *GlobalSum+=LocalSumOfSteps;
}

/// @brief 
/// @param size tamanho da matriz pesquisada
/// @param i distância em relaçao ao deslocamneto em linhas
/// @param j distância em relação ao deslocamento por colunas
/// @param S hipótese que verifica se um movimento para baixo é valido na matriz
/// @param SE hipótese que verifica se um movimento para baixo na diagonal direita da matriz é valido
/// @param SW hipótese que verifica se um movimento para baixo na diagonal esquerda da matriz é valido
/// @param W hipótese que verifica se um movimento para a esquerda na matriz é valido
/// @param E hipótese que verifica se um movimento para a direita na matriz é valido
void CreatingCoordinates(unsigned short int size,unsigned short int i,unsigned short int j, bool *S, bool *SE, bool *SW, bool *W, bool *E)
{
    unsigned short int Limit = size-1;

    *S = (i+1)<=Limit;
    *SE = (((i+1) <= Limit) && ((j+1) <= Limit));
    *SW = (((i+1) <= Limit) && ((j-1) > -1));
    *W = (j-1)>-1;
    *E = (j+1)<=Limit;

}

/// @brief 
/// @param FinalMatrix Matriz onde a busca está sendo realizada
/// @param size tamanho da matriz pesquisada
/// @param i distância em relaçao ao deslocamneto em linhas
/// @param j distância em relação ao deslocamento por colunas
/// @param lasti valor em relação ao deslocamento em linhas da última posição na matriz 
/// @param lastj valor em relação ao deslocamento em colunas da última posição na matriz 
void FivePossibleWays(MatrixElement *FinalMatrix, unsigned short int *i,unsigned short *j,unsigned short int size, unsigned short *lasti, unsigned short *lastj)
{

    unsigned short int IndexHigher = 0;
    unsigned short int PossibleHigher[5];
    unsigned short int Possiblei[5];
    unsigned short int Possiblej[5];
    unsigned short int Auxiliary = 0;

    PossibleHigher[0] = (*(FinalMatrix+(*i+1)*size+(*j))).Element;
    PossibleHigher[1] = (*(FinalMatrix+(*i+1)*size+(*j+1))).Element;
    PossibleHigher[2] = (*(FinalMatrix+(*i)*size+(*j+1))).Element;
    PossibleHigher[3] = (*(FinalMatrix+(*i+1)*size+(*j-1))).Element;
    PossibleHigher[4] = (*(FinalMatrix+(*i)*size+(*j-1))).Element;

    Possiblei[0] = *i+1;
    Possiblei[1] = *i+1;
    Possiblei[2] = *i;
    Possiblei[3] = *i+1;
    Possiblei[4] = *i;

    Possiblej[0] = *j;
    Possiblej[1] = *j+1;
    Possiblej[2] = *j+1;
    Possiblej[3] = *j-1;
    Possiblej[4] = *j-1;

    unsigned short int length = 5;

    for(int index = 0;index<length;index++)
    {
        if(PossibleHigher[index]>Auxiliary && (Possiblei[index]!=*lasti || Possiblej[index]!=*lastj))
            IndexHigher = index;

        Auxiliary = PossibleHigher[IndexHigher];
    }

    *lasti = *i;
    *lastj = *j;
    *i = Possiblei[IndexHigher];
    *j = Possiblej[IndexHigher];
}

/// @brief 
/// @param FinalMatrix Matriz onde a busca está sendo realizada
/// @param size tamanho da matriz pesquisada
/// @param i distância em relaçao ao deslocamneto em linhas
/// @param j distância em relação ao deslocamento por colunas
/// @param lasti valor em relação ao deslocamento em linhas da última posição na matriz 
/// @param lastj valor em relação ao deslocamento em colunas da última posição na matriz 
void SouthEastPossibleWays(MatrixElement *FinalMatrix, unsigned short int *i,unsigned short *j,unsigned short int size,unsigned short *lasti, unsigned short *lastj)
{

    unsigned short int IndexHigher = 0;
    unsigned short int PossibleHigher[3];
    unsigned short int Possiblei[3];
    unsigned short int Possiblej[3];
    unsigned short int Auxiliary = 0;

    PossibleHigher[0] = (*(FinalMatrix+(*i+1)*size+(*j))).Element;
    PossibleHigher[1] = (*(FinalMatrix+(*i+1)*size+(*j+1))).Element;
    PossibleHigher[2] = (*(FinalMatrix+(*i)*size+(*j+1))).Element;

    Possiblei[0] = *i+1;
    Possiblei[1] = *i+1;
    Possiblei[2] = *i;

    Possiblej[0] = *j;
    Possiblej[1] = *j+1;
    Possiblej[2] = *j+1;

    unsigned short int length = 3;

    for(int index = 0;index<length;index++)
    {
        if(PossibleHigher[index]>Auxiliary && (Possiblei[index]!=*lasti || Possiblej[index]!=*lastj))
            IndexHigher = index;

        Auxiliary = PossibleHigher[IndexHigher];
    }

    *lasti = *i;
    *lastj = *j;
    *i = Possiblei[IndexHigher];
    *j = Possiblej[IndexHigher];
}

/// @brief 
/// @param FinalMatrix Matriz onde a busca está sendo realizada
/// @param size tamanho da matriz pesquisada
/// @param i distância em relaçao ao deslocamneto em linhas
/// @param j distância em relação ao deslocamento por colunas
/// @param lasti valor em relação ao deslocamento em linhas da última posição na matriz 
/// @param lastj valor em relação ao deslocamento em colunas da última posição na matriz 
void SouthWestPossibleWays(MatrixElement *FinalMatrix, unsigned short int *i,unsigned short *j,unsigned short int size, unsigned short *lasti, unsigned short *lastj)
{
    unsigned short int IndexHigher = 0;
    unsigned short int PossibleHigher[3];
    unsigned short int Possiblei[3];
    unsigned short int Possiblej[3];
    unsigned short int Auxiliary = 0;

    PossibleHigher[0] = (*(FinalMatrix+(*i+1)*size+(*j))).Element;
    PossibleHigher[1] = (*(FinalMatrix+(*i+1)*size+(*j-1))).Element;
    PossibleHigher[2] = (*(FinalMatrix+(*i)*size+(*j-1))).Element;

    Possiblei[0] = *i+1;
    Possiblei[1] = *i+1;
    Possiblei[2] = *i;

    Possiblej[0] = *j;
    Possiblej[1] = *j-1;
    Possiblej[2] = *j-1;

    unsigned short int length = 3;

    for(int index = 0;index<length;index++)
    {
        if(PossibleHigher[index]>Auxiliary && (Possiblei[index]!=*lasti || Possiblej[index]!=*lastj))
            IndexHigher = index;

        Auxiliary = PossibleHigher[IndexHigher];
    }

    *lasti = *i;
    *lastj = *j;
    *i = Possiblei[IndexHigher];
    *j = Possiblej[IndexHigher];
}

/// @brief Mostra variáveis que englobam todas as pesquisas locais realizadas nas matrizes
/// @param ReadedMatrixes Número de matrizes percorridas
/// @param GlobalSum Soma dos elementos encontrados em todas as pesquisas locais
void JourneyMetrics(unsigned short int ReadedMatrixes, unsigned int GlobalSum)
{
    //Ideia de implementação:
        // [ ] - Mostrar a média de passos dados por matriz.
        // [ ] - Mostrar o número de passos dados no total
        // [ ] - Tentar elaborar uma métrica de score ou rankeamento usando 
            //      (Soma total dos elementos)/ (Número de passos dados)
        /*
            
            A pergunta que fica após essa métrica é se não existe uma forma melhor de percorrer essa matriz
            Ou seja, gerar um valor maior ou menor flexibilizando as regras de caminhamento, ou mudando a
            forma com que eles foram realizados.

        */

    cout<<"\n------------------------------Resumo de Métricas------------------------------\n";
    cout<<"\nSoma total dos elementos:............................................"<<GlobalSum;
    cout<<"\nNúmero de matrizes lidas:............................................"<<ReadedMatrixes;
}

#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.hpp"

using namespace std;


// Gera valores realmente aleatórios
unsigned short int RandomGenerator(unsigned short int a, unsigned short int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(a, b);
    return dis(gen);
}


unsigned short int SizeRecon()
{
    unsigned short int ArrayArea = 0;
    FILE *LocalPointer;
    LocalPointer = fopen("input.data", "r");
    fscanf(LocalPointer, "%hu", &ArrayArea);
    fclose(LocalPointer);
    return ArrayArea;
}

void MatrixScanner(unsigned short int size,MatrixElement *Matrix)
{
    /*
        Runs throuth a square "*Matrix" showing their values as they were placed on a matrix.
            unsigned short int size = The order of matrix.
            MatrixElement *Matrix = A matrix which someone deserve to see. 
    */
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

void CoordinateDefinition(unsigned short int *i,unsigned short int *j)
{
    cout<<"Insert a line (i): ";
    cin>>*i;
    cout<<"Insert a column (j): ";
    cin>>*j;

    cout<<"\n";
}

unsigned short int* RoadMapDefiner(vector<unsigned short int> Steps,unsigned short int HowManySteps)
{

    unsigned short int Counter=0;
    unsigned short int *Route = (unsigned short int*)malloc(sizeof(unsigned short int)*HowManySteps);


    for(auto index=Steps.begin();index!=Steps.end();index++)
    {
        Route[Counter] = *index;
        Counter+=1;
    }

    return Route;
}

void RoadMapViewer(unsigned short int *iRoute,unsigned short int *jRoute, unsigned short int HowManySteps, MatrixElement *FinalMatrix,unsigned short int size)
{
    unsigned short int SumOfEveryStep = 0;

    cout<<"A trajetória realizada com as especificações de pesquisa na matriz foram:"<<"\n";
    cout<<"   Passos         [i]   [j]   [Valor]"<<"\n";
    cout<<"-----------------------------------------\n";

    for(unsigned short int index=0;index<HowManySteps;index++)
    {
        cout<<index<<"º passo";
        cout<<"\t | "<<iRoute[index]<<" |"<<" | "<<jRoute[index]<<" | "<< " | "<<(*(FinalMatrix+iRoute[index]*size+jRoute[index])).Element<<" | \n";
        SumOfEveryStep+=(*(FinalMatrix+iRoute[index]*size+jRoute[index])).Element;
    }
    
    cout<<"-----------------------------------------\n";
    cout<<"A soma total foi:\t"<<SumOfEveryStep<<"\n\n";

}

void CreatingCoordinates(unsigned short int size,unsigned short int i,unsigned short int j, bool *S, bool *SE, bool *SW, bool *W, bool *E)
{
    unsigned short int Limit = size-1;

    *S = (i+1)<=Limit;
    *SE = (((i+1) <= Limit) && ((j+1) <= Limit));
    *SW = (((i+1) <= Limit) && ((j-1) > -1));
    *W = (j-1)>-1;
    *E = (j+1)<=Limit;

}

void FivePossibleWays(MatrixElement *FinalMatrix, unsigned short int *i,unsigned short *j,unsigned short int size, unsigned short int *IndexHigher, unsigned short *lasti, unsigned short *lastj)
{

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
            *IndexHigher = index;

        Auxiliary = PossibleHigher[*IndexHigher];
    }

    *lasti = *i;
    *lastj = *j;
    *i = Possiblei[*IndexHigher];
    *j = Possiblej[*IndexHigher];
}

void SouthEastPossibleWays(MatrixElement *FinalMatrix, unsigned short int *i,unsigned short *j,unsigned short int size, unsigned short int *IndexHigher, unsigned short *lasti, unsigned short *lastj)
{

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
            *IndexHigher = index;

        Auxiliary = PossibleHigher[*IndexHigher];
    }

    *lasti = *i;
    *lastj = *j;
    *i = Possiblei[*IndexHigher];
    *j = Possiblej[*IndexHigher];
}

void SouthWestPossibleWays(MatrixElement *FinalMatrix, unsigned short int *i,unsigned short *j,unsigned short int size, unsigned short int *IndexHigher, unsigned short *lasti, unsigned short *lastj)
{

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
            *IndexHigher = index;

        Auxiliary = PossibleHigher[*IndexHigher];
    }

    *lasti = *i;
    *lastj = *j;
    *i = Possiblei[*IndexHigher];
    *j = Possiblej[*IndexHigher];
}

#endif
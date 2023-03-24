
#include "structures.hpp"

using namespace std;
int main()
{
    unsigned short int size = SizeRecon();

    string Line;
    char string_generic[1];
    char *CharPointer = string_generic;
    int count = 1;
    MatrixElement FinalMatrix[size][size];
    unsigned short int MatrixLines = 0;
    unsigned short int MatrixColumns = 0;
    unsigned short int MatrixCounting = 0;
    ifstream File("./dataset/input.data");
    unsigned int GlobalSum = 0;

    // Percorrendo arquivo linha por linha e armazenando em Line:
    while (getline(File, Line))
    {
        // Criando um pointeiro de char do tamanho da linha do arquivo:
        char *copy = new char[Line.length() + 1];

        // Passando os dados de Line para copy e selecionando os dados desejados:
        strcpy(copy, Line.c_str());
        CharPointer = strtok(copy, " \n \0");

        if (count >= 2)
        {

            if(MatrixLines==size)
            {
                MatrixLines=0;
                MatrixColumns=0;
                cout<<"\n\n\n\n Nova iteração \n\n\n\t"<<++MatrixCounting<<"ª"<<" Matriz Lida\n";
                MatrixScanner(size,(MatrixElement *)FinalMatrix);
                
                //Iníciando variáveis para pesquisa na matriz:
                bool S,SW,SE,E,W;
                vector<unsigned short int> StepsOni;
                vector<unsigned short int> StepsOnj;
                vector<MatrixElement> StepsWeight;
                unsigned short int HowManySteps = 0;
                unsigned short int i = 0;
                unsigned short int j = 0;

                CoordinateDefinition(&i,&j);
                StepsOni.push_back(i);
                StepsOnj.push_back(j);
                StepsWeight.push_back(FinalMatrix[i][j]);

                unsigned short int lasti=i;
                unsigned short int lastj=j;

                while(true)
                {
                    CreatingCoordinates(size,i,j,&S,&SE,&SW,&W,&E);
                    unsigned short int IndexHigher = 0;
                    
                    if((S) && (SE) && (E) && (SW) && (W)) //Possibilidade de ir Leste, Oeste, Sul, Sudeste ou Sudoeste:
                    {
                        FivePossibleWays((MatrixElement *)FinalMatrix,&i,&j,size,&lasti,&lastj);
                        StepsOni.push_back(i);
                        StepsOnj.push_back(j);
                        StepsWeight.push_back(FinalMatrix[i][j]);
                        HowManySteps++;
                    }

                    else if(S && SE && E && !W && !SW) //Possibilidade de ir para Sul, Sudeste ou Leste:
                    {    

                        SouthEastPossibleWays((MatrixElement *)FinalMatrix,&i,&j,size,&lasti,&lastj);
                        StepsOni.push_back(i);
                        StepsOnj.push_back(j);
                        StepsWeight.push_back(FinalMatrix[i][j]);
                        HowManySteps++;
                    }

                   
                    else if((S) && (SW) && (W) && !SE && !SE)//Possibilidade de ir para Sul, Sudoeste ou Oeste:
                    {
                        SouthWestPossibleWays((MatrixElement *)FinalMatrix,&i,&j,size,&lasti,&lastj);
                        StepsOni.push_back(i);
                        StepsOnj.push_back(j);
                        StepsWeight.push_back(FinalMatrix[i][j]);
                        HowManySteps++;
                    }

                    
                    else if((E && W && !S && !SW && !SE) || (E && !W && !S && !SW && !SE)) //Caso especial de caminhada para o Leste:
                    {
                        lasti = i;
                        lastj = j;
                        i=i;
                        j = j+1;
                        StepsOni.push_back(i);
                        StepsOnj.push_back(j);
                        StepsWeight.push_back(FinalMatrix[i][j]);
                        HowManySteps++;
                    }


                    //Andando apenas para a esquerda, ou seja, chegada ao último elemento da matriz:
                    else if(!E && W && !S && !SW && !SE)
                    {   
                        HowManySteps++;
                        StepsOni.push_back(i);
                        StepsOnj.push_back(j);
                        StepsWeight.push_back(FinalMatrix[i][j]);

                        unsigned short int *iRoute = RoadMapDefiner(StepsOni,HowManySteps);
                        unsigned short int *jRoute = RoadMapDefiner(StepsOnj,HowManySteps);

                        RoadMapViewer(iRoute,jRoute,HowManySteps,(MatrixElement *)FinalMatrix,size , &GlobalSum);
                        MapOfTheJourney(iRoute,jRoute,size,HowManySteps);
                        break;
                    }
                }
            }
            else
            {
                MatrixColumns = 0;
                MatrixLines += 1;
            }
        }
        
        cout << "\n\n";
        while (CharPointer != NULL)
        {
            MatrixColumns += 1;

            int z = atoi(CharPointer);
            
            FinalMatrix[MatrixLines-1][(MatrixColumns-1)].Element = z;

            CharPointer = strtok(NULL, " \n \0");
        }
        count += 1;
    }
    
    JourneyMetrics(MatrixCounting, GlobalSum);

    File.close();

    return 0;
}

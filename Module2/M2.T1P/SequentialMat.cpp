#include <stdio.h> 
#include <stdlib.h> 
#include <chrono> 

using namespace std;

#define NUM 500

int InputMat1[NUM][NUM];
int InputMat2[NUM][NUM];
int ResultMat[NUM][NUM];



void createRandom(int randomA[NUM][NUM])
{
   for(int i = 0; i < NUM; i++)
   {
      for (int j = 0; j < NUM; j++)
      {
         randomA[i][j] = rand() % 100;
      }
   }
}

void printMat(int randomA[NUM][NUM])
{
    for (int i = 0; i < NUM; i++)
    {
        for (int j = 0; j < NUM; j++)
        {
            printf("%i", randomA[i][j]);
        }
    }
}

void SeqMat()
{
   int v; 
   for (int i = 0; i < NUM; i++)
   {
      for (int j = 0; j < NUM; j++)
      {
         v = 0;
         for (int c = 0; c < NUM; c++)
         {
            v += InputMat1[i][j]*InputMat2[i][j];
         }
         ResultMat[i][j] = v;
      }
   }
}



int main()
{

   printf("MATRIX SIZE %d\n", NUM);
   createRandom(InputMat1);
   createRandom(InputMat2);

   //printf("Matrix 1:\n");
   //printMat(InputMat1);
   //printf("Matrix 2:\n");
   //printMat(InputMat1);
   //printf("Result Matrix:\n");
   //printMat(ResultMat);

   auto start = chrono::high_resolution_clock::now();

   SeqMat();

   auto end = chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

   printf("taken time for sequential %li: ms\n", duration.count());

}





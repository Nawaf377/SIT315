#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <pthread.h>
#include <omp.h>


using namespace std;

#define NUM 500
#define NUM_THREADS 8

int InputMat1[NUM][NUM];
int InputMat2[NUM][NUM];
int ResultMat[NUM][NUM];

void ompMat()
{
    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 0; i < NUM; i++)
        {
            for(int j = 0; j < NUM; j++)
            {
                int v = 0;
                for(int c = 0; c < NUM; c++ )
                {
                    v += InputMat1[i][c] * InputMat2[c][j];
                }
                ResultMat[i][j] = v;
            }

        }
    }

}


void createRandom(int randomA[NUM][NUM])
{
   for (int i = 0; i < NUM; i++)
   {
      for (int j = 0; j < NUM; j++)
      {
         randomA[i][j] = rand() % 10;
      }
   }
}


void printMat(int randomA[NUM][NUM])
{
   for (int i = 0; i < NUM; i++)
   {
      printf("[");
      for (int j = 0; j < NUM; j++)
      {
         printf(" %i", randomA[i][j]);
      }
      printf("]\n");
   }
}



int main()
{
    omp_set_num_threads(NUM_THREADS);
  
   printf("MATRIX SIZE %d\n", NUM);
   createRandom(InputMat1);
   createRandom(InputMat2);

   //printf("Matrix 1:\n");
   //printMat(InputMat1);
   //printf("Matrix 2:\n");
   //printMat(InputMat2);

   auto start = chrono::high_resolution_clock::now();
   ompMat();

   auto end = chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

   //printf("Result Matrix:\n");
   //printMat(ResultMat);
   printf("number of thhreads: %d \n", NUM_THREADS);
   printf("taken time for OMP: %li ms\n", duration.count());

}




#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <mpi.h>
#define NUMBERS 100
int main(int argc,char** argv) 
{
 int rank,size;
 int numbers[NUMBERS];
 int local_sum=0,global_sum=0;
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);
 srand(rank);
 for(int i=0;i<NUMBERS;i++) 
 {
  numbers[i]=rand()%100;
  local_sum+=numbers[i];
 }
 MPI_Reduce(&local_sum,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
 if(rank==0) 
 {
  printf("Sum of %d random numbers: %d\n",NUMBERS*size,global_sum);
 }
 MPI_Finalize();
 return 0;
}
/*
bcs@bcs-HCL-Desktop:~$ mpicc Mpi1.c -o Mpi1
bcs@bcs-HCL-Desktop:~$ mpiexec -n 4 ./Mpi1
Sum of 400 random numbers: 20982
*/

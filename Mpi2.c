#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <mpi.h>
#define NUMBERS 100
int main(int argc,char** argv) 
{
 int rank,size;
 int numbers[NUMBERS];
 int local_min=INT_MAX,local_max=INT_MIN;
 int global_min,global_max;
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);
 srand(rank);
 for(int i=0;i<NUMBERS;i++) 
 {
  numbers[i]=rand()%100;
  if(numbers[i]<local_min) 
  {
   local_min=numbers[i];
  }
  if(numbers[i]>local_max) 
  {
   local_max = numbers[i];
  }
 }
 MPI_Allreduce(&local_min,&global_min,1,MPI_INT,MPI_MIN,MPI_COMM_WORLD);
 MPI_Allreduce(&local_max,&global_max,1,MPI_INT,MPI_MAX,MPI_COMM_WORLD);
 printf("Process %d: Local min = %d, Local max = %d\n",rank,local_min,local_max);
 if (rank == 0) 
 {
  printf("Global min = %d, Global max = %d\n", global_min, global_max);
 }
 MPI_Finalize();
 return 0;
}
/*
bcs@bcs-HCL-Desktop:~$ mpicc Mpi2.c -o Mpi2
bcs@bcs-HCL-Desktop:~$ mpiexec -n 4 ./Mpi2
Process 0: Local min = 2, Local max = 99
Global min = 1, Global max = 99
Process 1: Local min = 2, Local max = 99
Process 2: Local min = 1, Local max = 99
Process 3: Local min = 1, Local max = 99
bcs@bcs-HCL-Desktop:~$ 
*/

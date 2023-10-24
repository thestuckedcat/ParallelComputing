#include<unistd.h>  //for sleep
#include<stdio.h>   
#include<mpi.h>     //for MPI

int main(int argc, char *argv[]){
    int mype;
    
    MPI_Init(&argc,&argv);                  // Initialize MPI environment, which is essential in MPI programm before MPI method
    MPI_Comm_rank(MPI_COMM_WORLD,&mype);    // Identify rank(Identify code) of process

    double t1,t2;

    t1 = MPI_Wtime();
    sleep(10);
    t2 = MPI_Wtime();

    if(mype == 0)
        printf("Elapsed time is %f secs\n",t2-t1);

    MPI_Finalize();
}
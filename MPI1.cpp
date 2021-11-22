
//Implement an MPI program to send integer from one process to another.

#include <iostream>
#include "mpi.h"
using namespace std;
int main()
{
    int rank, num_receive, send=114;
    //cin >> numbertosend;
    MPI_Status status;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) 
    {
        MPI_Recv(&num_receive, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        printf("The received integer is: %d\n", num_receive);
    }
    else if (rank == 1)
        MPI_Send(&send, 1, MPI_INT, 0, 10, MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;
}

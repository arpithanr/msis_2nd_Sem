/*** Program to define and initialise a matrix to all zero elements, and then update it's 0th row by 3 threads ***/

/*** Illustrated using the lock() routines of OpenMP, and also using the ctitical directive of omp ***/


/*** run your program (i) with and without the usage of locks, (ii) with and without the usage of critical directive and observe the result ***/

#include <omp.h>
#include <stdio.h>

#define N 3

int mat[N][N];
omp_lock_t m1;

void update_mat(int row, int col, int val) 
{
    // Acquire the matrix lock
   omp_set_lock(&m1);

    printf("Thread %d updates matrix[%d][%d] by value %d\n", omp_get_thread_num(), row, col, val);

    // Perform some work on the matrix 
    mat[row][col] += val;

    // Release the matrix lock
   omp_unset_lock(&m1);
}

void print_mat() 
{
    //every thread has to print the matrix
   
    
    #pragma omp critical  //Similar to using locks
    {
    printf("Thread %d printing the matrix...\n", omp_get_thread_num());

    
    printf("Matrix contents:\n");
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            printf("%d   ", mat[i][j]);
        }
        printf("\n");
    }
   
    } //End Critical

    
}


int main() 
{
    
    omp_init_lock(&m1);  // Initialize the lock for the matrix
    
    // Initialize the matrix to all zeroes
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            mat[i][j] = 0;
        }
    }



    #pragma omp parallel num_threads(3) //0th row elements are updated by all the three threads
    {
        // Each thread performs operations on the matrix
         update_mat(0, 0, 100);  //update_mat(row, col, value)
         update_mat(0, 1, 200);
         update_mat(0, 2, 300);

        // Synchronize before processing the matrix to ensure updates are visible to all threads
        #pragma omp barrier  //check with and without barrier
           print_mat();
    }

    
    omp_destroy_lock(&m1); // Destroy the lock for the matrix

    return 0;
}

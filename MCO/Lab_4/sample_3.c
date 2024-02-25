/*** parallelising the for loop ***/
#include <omp.h>
#include <stdio.h>

int main() {
    const int N = 10;
    #pragma omp parallel for // change N to the total number of threads omp_get_num_threads()
            for (int i = 0; i < N; i++)
            {
                // Each thread works on a subset of loop iterations
                printf("i%d by thread_number %d\n", i, omp_get_thread_num());
            }
        // Rest of the program...
    return 0;
}
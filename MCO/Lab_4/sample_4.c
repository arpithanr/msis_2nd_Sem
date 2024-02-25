/*** parallelising the for loop: chuk size 4 ***/
#include <omp.h>
#include <stdio.h>

int main() {

    const int N = 10;
    #pragma omp parallel for schedule(dynamic, 4)
        for (int i = 0; i < N; i++)
        {
            // Each thread works on a subset of loop iterations
            printf("i%d by thread_number %d\n", i, omp_get_thread_num());
        }
        // Rest of the program...
    return 0;
} /*** End ***/
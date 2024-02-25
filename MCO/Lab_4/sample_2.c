/* program to set the number of threads */
#include <omp.h>
#include <stdio.h>

int main() {
    // Set the number of threads to say, 3.
    //omp_set_num_threads(5);
    #pragma omp parallel
    {
        printf("Hello from %d\n",omp_get_thread_num());
    }
    return 0;
}
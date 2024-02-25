/*** Hello World program ***/
#include <omp.h>
#include <stdio.h>

int main() {

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("Hello World from thread %d\n", tid);
    }
    return 0;
}
/*** End of program ***/
/*In the above, the #pragma omp parallel directive creates a
team of threads, and the enclosed block is executed by each
thread. */
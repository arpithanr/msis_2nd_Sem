/* Consider an integer matrix of order n*m. 
Create three threads using omp where one of 
them displays the matrix elemrnts, the second
 one reverses each matrix element and the third
  one cubes every element in place. 
Use critical section or omp lock routines to
 ensure that the threads do not get into race situation.*/

 #include <stdio.h>
#include <omp.h>

#define N 3
#define M 3

int matrix[N][M] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Function to display the matrix
void displayMatrix() {
    printf("Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to reverse each matrix element
void reverseMatrix() {
    #pragma omp parallel for collapse(2) shared(matrix)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int temp = 0;
            #pragma omp critical
            {
                while (matrix[i][j] != 0) {
                    temp = temp * 10 + matrix[i][j] % 10;
                    matrix[i][j] /= 10;
                }
                matrix[i][j] = temp;
            }
        }
    }
}

// Function to cube each matrix element in place
void cubeMatrix() {
    #pragma omp parallel for collapse(2) shared(matrix)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            #pragma omp critical
            matrix[i][j] = matrix[i][j] * matrix[i][j] * matrix[i][j];
        }
    }
}

int main() {
    // Display original matrix
    displayMatrix();

    // Reverse each matrix element
    reverseMatrix();

    // Display reversed matrix
    printf("\nMatrix after reversing each element:\n");
    displayMatrix();

    // Cube each matrix element
    cubeMatrix();

    // Display matrix after cubing each element
    printf("\nMatrix after cubing each element:\n");
    displayMatrix();

    return 0;
}

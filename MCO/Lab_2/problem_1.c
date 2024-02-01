/*(i) Write a C program to search for a given element in a matrix. The program should take a matrix and a target
element as input, and it should output whether the element is present in the matrix or not.

(ii) Modify your code so that you convert the code into a function called search().Signature of search() can be as below:
int search(int mat[][], int rows, int cols, int key).Let the search function return 0 on finding the key,
and return -1 if the key is not present in the matrix. Write a suitable main function which invokes
search() and observe your results. */

#include <stdio.h>

// Function to search for a given element in a matrix
int search(int mat[][3], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) {
                return 0; // Key found
            }
        }
    }
    return -1; // Key not found
}

int main() {
    // Example matrix
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    // Example target element
    int target = 5;

    // Calling the search function
    int result = search(matrix, 3, 3, target);

    // Output based on the result
    if (result == 0) {
        printf("Element found in the matrix.\n");
    } else {
        printf("Element not found in the matrix.\n");
    }

    return 0;
}


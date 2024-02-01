/*(i) Write a C program to search for a given element in a matrix. The program should take a matrix and a target
element as input, and it should output whether the element is present in the matrix or not.

(ii) Modify your code so that you convert the code into a function called search().Signature of search() can be as below:
int search(int mat[][], int rows, int cols, int key).Let the search function return 0 on finding the key,
and return -1 if the key is not present in the matrix. Write a suitable main function which invokes
search() and observe your results. */

#include <stdio.h>

int main(){

    int rows, cols, target;
    int mat[100][100];

    printf("Enter the number of rows and columns of the matrix: \n");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix: \n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Enter the target element to search: \n");
    scanf("%d", &target);

    int found = 0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(mat[i][j] == target)
            {
                found = 1;
                break;
            }       
        }
    }
     if (found == 1) {
        printf("Element %d found in the matrix.\n" , target);
    } else {
        printf("Element %d not found in the matrix.\n", target);
    }

    return 0;
}


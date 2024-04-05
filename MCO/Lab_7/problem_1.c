/* Write a program which creates 3 threads of which one reads a text file 
of your current directory and counts the total lines, characters and blanks. 
Another threads appends a message "hello world" to the file. 
Another file appends five lines of user provided text to the same file. 
Use critical section or omp lock routines to ensure that the threads 
do not get into race situation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Mutex lock
pthread_mutex_t lock;

// Function to read file and count lines, characters, and blanks
void *readFile(void *filename) {
    char *file_name = (char *)filename;
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        pthread_exit(NULL);
    }

    int total_lines = 0, total_chars = 0, total_blanks = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        total_lines++;
        total_chars += strlen(buffer);
        if (strcmp(buffer, "\n") == 0 || strcmp(buffer, "\r\n") == 0) {
            total_blanks++;
        }
    }

    fclose(file);

    pthread_mutex_lock(&lock);
    printf("Total lines: %d\n", total_lines);
    printf("Total characters: %d\n", total_chars);
    printf("Total blanks: %d\n", total_blanks);
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

// Function to append "hello world" to the file
void *appendHello(void *filename) {
    char *file_name = (char *)filename;
    pthread_mutex_lock(&lock);
    FILE *file = fopen(file_name, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        pthread_exit(NULL);
    }
    fprintf(file, "hello world\n");
    fclose(file);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

// Function to append five lines of user-provided text to the file
void *appendUserText(void *filename) {
    char *file_name = (char *)filename;
    pthread_mutex_lock(&lock);
    FILE *file = fopen(file_name, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        pthread_exit(NULL);
    }
    printf("Enter five lines of text to append to the file:\n");
    char buffer[1024];
    for (int i = 0; i < 5; ++i) {
        fgets(buffer, sizeof(buffer), stdin);
        fprintf(file, "%s", buffer);
    }
    fclose(file);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    char filename[] = "sample.txt";
    pthread_t threads[3];

    // Initialize mutex lock
    pthread_mutex_init(&lock, NULL);

    // Create threads
    pthread_create(&threads[0], NULL, readFile, (void *)filename);
    pthread_create(&threads[1], NULL, appendHello, (void *)filename);
    pthread_create(&threads[2], NULL, appendUserText, (void *)filename);

    // Join threads
    for (int i = 0; i < 3; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex lock
    pthread_mutex_destroy(&lock);

    return 0;
}

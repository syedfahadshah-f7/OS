#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h> // for usleep

#define NUM_READERS 5
#define NUM_WRITERS 2
#define STRING_LENGTH 60

pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
sem_t mutex, rw_mutex;
int readers_count = 0;
FILE *file;

char generateRandomChar() {
    return (char)('a' + rand() % 26); // Generating a random lowercase character
}

void *reader(void *arg) {
    long id = (long)arg; // Cast argument properly
    while (1) {
        sem_wait(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&rw_mutex);
        }
        sem_post(&mutex);

        // Reading from file
        fseek(file, 0, SEEK_SET);
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            fprintf(stdout, "Reader %ld: %s", id, buffer);
        }

        sem_wait(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&rw_mutex);
        }
        sem_post(&mutex);

        // Perform other tasks
        usleep(1000); // sleep for 1 millisecond
    }
}

void *writer(void *arg) {
    long id = (long)arg; // Cast argument properly
    while (1) {
        sem_wait(&rw_mutex);

        // Generate random string to be written to file
        char randomString[STRING_LENGTH + 1]; // +1 for null terminator
        for (int i = 0; i < STRING_LENGTH; i++) {
            randomString[i] = generateRandomChar();
        }
        randomString[STRING_LENGTH] = '\0'; // Null terminate the string

        // Writing to file
        fseek(file, 0, SEEK_END);
        fprintf(file, "%s\n", randomString); // writer to file on drive
        fprintf(stdout, "Writer %ld: %s\n", id, randomString); // display
        fflush(file);

        sem_post(&rw_mutex);

        // Perform other tasks
        usleep(1000); // sleep for 1 millisecond
    }
}

int main() {
    // Open the file
    file = fopen("shared_file.txt", "a+"); // Open for reading and appending
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);

    // Create reader and writer threads
    for (long i = 0; i < NUM_READERS; i++) {
        pthread_create(&readers[i], NULL, reader, (void *)i);
    }
    for (long i = 0; i < NUM_WRITERS; i++) {
        pthread_create(&writers[i], NULL, writer, (void *)i);
    }

    // Join reader and writer threads
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    // Clean up (unreachable due to infinite loops but still good practice)
    fclose(file);
    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);

    return 0;
}

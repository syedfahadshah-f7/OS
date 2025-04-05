### Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *CalculateAverage(void *arg) {
    char **argv = (char **)arg;
    int sum = 0, count = 0;

    for (int i = 1; argv[i] != NULL; i++) {  
        sum += atoi(argv[i]);
        count++;
    }

    printf("Average: %.2f\n", (double)sum / count);
    return NULL;
}

void *MinValue(void *arg) {
    char **argv = (char **)arg;
    int min= 10000;

    for (int i = 1; argv[i] != NULL; i++) {  
        if(min > atoi(argv[i])){
        min = atoi(argv[i]);
        }
    }

    printf("Min Value in Array: %d\n", min);
    return NULL;
}
void *MaxValue(void *arg) {
    char **argv = (char **)arg;
    int max= 0;

    for (int i = 1; argv[i] != NULL; i++) {  
        if(max < atoi(argv[i])){
        max = atoi(argv[i]);
        }
    }

    printf("Max Value in Array: %d\n", max);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide integer arguments.\n");
        return 1;
    }
    
    pthread_t id1,id2,id3;
    pthread_create(&id1, NULL, CalculateAverage, (void *)argv);
    pthread_create(&id2,NULL,MinValue,(void *)argv);
    pthread_create(&id3,NULL,MaxValue,(void *)argv);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id2, NULL);
    
    pthread_exit(NULL);
    return 0;
}

```
### Output
![image](https://github.com/user-attachments/assets/f4e8173c-a808-481b-921d-7865f8e9f060)

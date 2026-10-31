#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct thread_data {
    int nrep;
    char msg[10];
};

void* thread_func(void* arg)
{
    struct thread_data *data = (struct thread_data *) arg;
    
    char* msg = (*data).msg;
    int nrep = (*data).nrep;
    
    int i = 0;

    while(i < nrep) {
        usleep(rand() % 3000000);
        printf("(%02d) %s\n", i, msg);
        i++;
    }
    
    pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
    pthread_t th1, th2, th3;

    struct thread_data d1 = {5, "Hello!"};
    struct thread_data d2 = {3, "Hola!"};
    struct thread_data d3 = {4, "Namaste!"};

    pthread_create(&th1, NULL, thread_func, &d1);
    pthread_create(&th2, NULL, thread_func, &d2);
    pthread_create(&th3, NULL, thread_func, &d3);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);

    return 0;
}

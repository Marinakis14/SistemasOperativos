#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define TOTAL_COUNT 400000000

long x = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_func(void* arg)
{
  long count = *((long*) arg);
  long local_x = 0;

  for (long i = 0; i < count; i++) {
	  local_x ++;
  }

  pthread_mutex_lock(&mutex);
  x += local_x;
  pthread_mutex_unlock(&mutex);
}

int main(int argc, char* argv[])
{
  long total_count = TOTAL_COUNT;
  int nthreads;

  if (argc == 1)
    nthreads = 1;
  else
    nthreads = atoi(argv[1]);

  pthread_t th[nthreads];
  long th_count[nthreads];

  for (int i = 0; i < nthreads; i++) {
    th_count[i] = total_count/(nthreads-i);
    pthread_create(&th[i], NULL, thread_func, &th_count[i]);
    total_count -= th_count[i];
  }

  for (int i = 0; i < nthreads; i++)
    pthread_join(th[i], NULL);

  printf("%ld\n", x);

  return 0;
}


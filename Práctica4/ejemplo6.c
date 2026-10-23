#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define START_VAL 100000000 

void mysigaction(int n, siginfo_t * info, void * context);

void othersigaction(int n, siginfo_t * info, void * context);

void othersigaction2(int n, siginfo_t * info, void * context);

int main(int argc, char* argv[])
{
        long i,j;

        struct sigaction a;

        a.sa_sigaction = mysigaction;
        sigemptyset(&a.sa_mask);
        a.sa_flags = SA_SIGINFO;

        sigaction(SIGINT, &a, NULL);

        a.sa_sigaction = othersigaction;

        sigaction(SIGUSR1, &a, NULL);

	a.sa_sigaction = othersigaction2;

	sigaction(SIGALRM, &a, NULL);

	alarm(10);
        for(i = START_VAL; ; i++) {
                for(j = 2 ; j < i; j++)
                        if ((i%j) == 0)
                                break;
                if(j==i)
                        printf("%ld\n", i);
        }

        return 0;
}

void mysigaction(int n, siginfo_t * info, void * context)
{
        printf("It is a good day to die... but the day is not yet over.\n");
        printf("Señal recibida del proceso con PID: %d\n", info->si_pid);
        signal(SIGINT, SIG_DFL);
}

void othersigaction(int n, siginfo_t * info, void *context)
{
        printf("¡He recibido una señal de usuario!\n");
}

void othersigaction2(int n, siginfo_t * info, void *context)
{
        printf("¡He recibido una señal de alarma!\n");
	raise(SIGKILL);
}


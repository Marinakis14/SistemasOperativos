#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

void alarma(int n, siginfo_t * info, void * context);
void terminar(int n, siginfo_t * info, void * context);

double piq, xdelta, ydelta;
long i, niter, in, out, tlim;

int main(int argc, char * argv[])
{
	printf("Proceso lanzado(PID=%d)\n", getpid());

	struct sigaction a;

	a.sa_sigaction = alarma;
        sigemptyset(&a.sa_mask);
        a.sa_flags = SA_SIGINFO;

        sigaction(SIGALRM, &a, NULL);

	a.sa_sigaction = terminar;

	sigaction(SIGINT, &a, NULL);

        if(argc != 3)
        {
                printf("Invalid number of arguments. Usage:\n");
                printf("%s <iterations>\n", argv[0]);
                exit(-1);
        }
        niter = atol(argv[1]);
	tlim = atol(argv[2]);

        in = out = 0;
	srand48(time(NULL));

	alarm(tlim);

        for(i = 0; i < niter; i++)
        {
                xdelta = drand48() - 0.5;
                ydelta = drand48() - 0.5;

                if(xdelta*xdelta + ydelta*ydelta <= 0.25)
                        in++;
                else
                        out++;
        }
        piq=(double) in/(double)(in + out);

        printf("Finalizado después de %ld iteraciones.\n", niter);
        printf("Valor calculado: %lf\n", 4*piq);

        return 0;


}

void alarma(int n, siginfo_t * info, void * context)
{
	printf("Finalizado por timeout tras %ld iteraciones.\n", i);
	piq=(double) in/(double)(in + out);
	printf("Valor calculado: %lf\n", 4*piq);
	exit(0);
}

void terminar(int n, siginfo_t * info, void * context)
{
        printf("Finalizado por interrupción.\n");
        piq=(double) in/(double)(in + out);
        printf("Valor calculado: %lf\n", 4*piq);
        exit(0);
}


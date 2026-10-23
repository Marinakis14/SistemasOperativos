#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) 
{
	pid_t pid = fork();
	if (pid == 0) {
		printf("Soy (%d), mi padre es (%d).\n", getpid(), getppid());
	} else {
		printf("Soy (%d), mi hijo es (%d).\n", getpid(), pid);
	}

	return 0;
}

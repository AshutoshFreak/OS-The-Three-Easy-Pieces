#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
	printf("Hello World! (pid: %d)\n", (int) getpid());
	int x = 100;
	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr, "Fork Failed!\n");
		exit(1);
	}
	else if (rc == 0)
	{
		printf("Hello, I am the child (pid: %d))\n", (int) getpid());
		x = 50;
		printf("Value of x in child: %d\n", x);
	}
	else
	{
		int rc_wait = wait(NULL);
		printf("Hello, I am the parent (pid: %d))\n", (int) getpid());
		printf("Value of x in parent: %d\n", x);
	}
	return 0;
}

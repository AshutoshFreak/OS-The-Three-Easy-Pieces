#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>

int suspend(int seconds)
{
	while(seconds)
		seconds = sleep(seconds);
}


int main(int argc, char *argv[])
{
	int rc = fork();
	int i = 0;
	close(STDOUT_FILENO);
	open("5.2.output", O_CREAT | O_WRONLY | O_TRUNC | S_IRWXU);
	if (rc < 0)
	{
		printf("fork failed\n");
		exit(1);
	}
	else if (rc == 0)
	{
		close(STDOUT_FILENO);
		open("5.2.output", O_CREAT | O_WRONLY | O_TRUNC | S_IRWXU);
		while(i < 10)
		{
			printf("A");
			suspend(1);
		}
	}
	else
	{
		while(i < 10)
		{
			printf("B");
			suspend(1);
		}
	}
}

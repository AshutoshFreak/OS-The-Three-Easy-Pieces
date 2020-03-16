#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include <sched.h>

int fn(void *arg)
{
	int var;
	printf("\nHi There! I am the clone process. \nI don't really want to create any mischief like the previous child. So I will just exit as soon as you press Enter.\n\n\nPress Enter to continue.\n");
	getchar();
	return 0;
}


int main(int argc, char *argv[])
{
	char* c;
	FILE *fptr;
	void *pchild_stack = malloc(1024 * 1024);
	printf("Hello! I am the parent process. My PID is %d\nYou can attach me to strace now. Press Enter when you are done.", (int) getpid());
	getchar();
	int rc = fork();
	if (rc < 0)
	{
		// fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc == 0)
	{
		// child (new process)
		printf("\nHello, I am the child. My PID is %d\n", (int) getpid());
	sleep(3);
	printf("\nWriting to file '123temp.txt'. This file will be deleted before my parent process terminates.\n");
	fptr = fopen("123temp.txt", "w");
	fprintf(fptr,"Hi there! This is just a test content. If this file exists for more than 1 second, it means that there was some problem with the executing process.");
	sleep(6);
	fclose(fptr);
	printf("\nWritten. Now I will exit! Bye!\n");
	}
	else
	{
		// parent goes down this path (main)
		int rc_wait = wait(NULL);
		sleep(5);
		printf("\nI am the parent process. Looks like my child has created some garbage file in your computer. I am reading the file contents now.\n");
		fptr = fopen("123temp.txt", "r");
		fscanf(fptr, c);
		fclose(fptr);
		sleep(8);
		printf("\nRead. I will be deleting what my mischievous child created.\n");
		remove("123temp.txt");
		sleep(5);
		printf("\nDeleted. Now I will be creating a clone process.\n");
		sleep(4);
		if (pchild_stack == NULL ) 
		{
  			printf("ERROR: Unable to allocate memory for cloning.\n");
  			exit(EXIT_FAILURE);
  		}

		int pid = clone(fn, pchild_stack + (1024 * 1024), SIGCHLD, argv[1]);
   		
		if ( pid < 0 )
		{
        		printf("ERROR: Unable to create the child process for cloning.\n");
        		exit(EXIT_FAILURE);
   		}
		wait(NULL);
		free(pchild_stack);
		printf("\nLooks like clone child process has exited. Now I'll exit too. Have a great day!\n");
	}
	return 0;
}

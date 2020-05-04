#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main( int argc, char* argv[])
{
	int *ptr;
	char filename[100];
	int PID=getpid();
	printf("Process id: %d\n",PID);
	int x;
	if(argc>1)
	{
		char* a=argv[1];
		x=atoi(a);
	}
	else
	{
		printf("Please enter an argument denoting the size of array to be created . Default set to 50.\n");
		x=50;
	}
	

	
	sprintf(filename,"/proc/%d/statm",PID);
	ptr = (int*) malloc(x * sizeof(int));
	int num;
	FILE* fp;
	fp=fopen(filename,"r");
	if(fp == NULL)
	{
		printf("Cant open the file");
	}
	
	else
	{
		printf("Contents of /proc/[pid]/statm are : \n");
		for(int i=0;i<7;i++)
		{
			fscanf(fp,"%d",&num);
			printf("%d \n",num);
		}
	}
	return 0;
}


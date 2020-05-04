#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int ac, char **av)
{
	char *str;
	int i = 1;

	if (ac == 2)
	{
		str = malloc(len(av[1]) + 1);
		strcpy(str, av[1]);
	}
	while (i)
	{
		printf("[%d] %s - addr: %p\n", i, str, str);
		sleep(1);
		i++;
	}
	free(str);
	return (0);
}

int len(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}


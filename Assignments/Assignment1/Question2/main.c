/* This file is the solution to Question 2 of Asignment 1. It belongs to ~/xinu/system */

/*  main.c  - main */

#include <xinu.h>

process	main(void)
{
	// initialise the shell respawn counter
	int count = 0;
	/* Run the Xinu shell */

	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));
	// increment the counter as the shell gets created
	count += 1;
	/* Wait for shell to exit and recreate it */

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell: Counter = %d\n\n", count);
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
		// incrementing the counter as the shell gets respawned each time
		count += 1;
	}
	return OK;
    
}

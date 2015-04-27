/*
 * waitdemo1.c - shows how parent pauses until child finishes.
 */

#include <stdio.h>
#include <stdlib.h>

#define DELAY 2

main()
{
	int newpid;/* save the number of pid */

	void child_code(), parent_code();

	printf("Before: my pid is %d\n", getpid());

	if( (newpid = fork()) == -1)
		perror("fork");
	else if( newpid == 0)
		child_code(DELAY);/* child processes */
	else
		parent_code(newpid);/* parent processes */
}

/*
 * new process takes a nap and then exits
 */

void child_code(int delay)
{
	printf("child %d here. will sleep for %d seconds\n", getpid(), delay);
		sleep(delay);
	printf("child done. about to exit\n");
	exit(17);
}

/*
 * parent waits for child then prints a message
 */

void parent_code(int childpid)
{
	int wait_rv;	/* return value from wait() */
	wait_rv = wait(NULL);
	printf("done waiting for %d. Wait returned: %d\n", childpid, wait_rv);
}




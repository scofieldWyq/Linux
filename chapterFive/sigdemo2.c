/* sigdemo1.c - shows how a signal handler works.
 * - run this and press Ctl - C a few times
 */

#include <stdio.h>
#include <signal.h>

main()
{
	signal( SIGINT,SIG_IGN);	/* install the handler */
	printf(" you can't stop me! \n");

	while(1){
		sleep(1);
		printf("haha\n");
	}

}




/*
 * smsh2.c small - shell version 2
 *  small shell that supports command line parsing
 *  and if .. then ..else.fi logic(by calling process())
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "smsh.h"

#define DFL_PROMPT	">"

int main()
{
	char *cmdline, *prompt, **arglist;
	int result, process( char **) ;
	void setup();

	prompt = DFL_PROMPT;
	setup();/* close the INT, QUIT signal */

	while( (cmdline = next_cmd(prompt, stdin)) != NULL){ /* read the cmdline */
		if( (arglist = splitline(cmdline)) != NULL){ /* split the cmdline into string array */
			result = process(arglist);	     /* execute arglist as an line command like shell */
			freelist(arglist);		     /* when execute done, free the args list */
		}
		free(cmdline);				     /* all is done, free the cmdline buffer */
	}

	return 0;
}

void setup()
/*
 * purpose: initialize shell
 * returns: nothing. calls fatal() if trouble
 */
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void fatal(char *s1, char *s2, int n)
{
	fprintf(stderr, "Error: %s, %s\n", s1, s2);
	exit(n);
}



/*
 * hello2.c
 * purpose	show how to use curses functions with a loop
 * outline	initialize, draw stuff, wrap up
 *
 * complie "cc <file name> -o [ file name ] -lcurses".
 *
 */

#include <stdio.h>
#include <curses.h>

main()
{
	int i;
		/* turn on curses */
	initscr();
	clear();	/* draw some stuff */
			/* in a loop */
	for(i=0; i < LINES; i++){
		move(i, i+i);
		if( i%2 == 1)
			standout();
		addstr("Hello, world");
		if( i%2 == 1)
			standend();
	}

	refresh();	/* update the screen */
	
	getch();	/* wait for use input */
	endwin();	/* reset the tty etc */
}


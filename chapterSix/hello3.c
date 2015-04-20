/*
 * hello3.c
 * purpose using refresh and sleep for animated effects
 * outline initilaze, draw stuff, wrap up
 *
 * system call: sleep();
 */
#include <stdio.h>
#include <curses.h>

main()
{
	int i;

	initscr();	/* start curses */

	clear();	/* clear the screen */
	for(i=0; i< LINES; i++){
		move(i, i+i);
		if( i%2 == 1)
			standout();
		addstr("Hello, world");
		if( i%2 == 1)
			standend();
		sleep(1);

		refresh();/* refresh the screen */

	}
	endwin();	/* close the curses */
}


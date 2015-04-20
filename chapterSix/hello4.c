/*
 * hello4.c
 * purpose show how to use erase, time, and draw for animation
 * animation .....
 */

#include <stdio.h>
#include <curses.h>

main()
{
	int i;

	initscr();	/* open the curses lib */

	clear();

	for(i=0; i< LINES; i++){
		move(i, i+i);
		if( i%2 == 1)
			standout();
		addstr("Hello, world");
		if( i%2 == 1)
			standend();
		refresh();

		sleep(1);

		move(i, i+i);	/* move back */
		addstr("            ");/* erase line */
	}
	endwin();	/* close the curses lib */
}


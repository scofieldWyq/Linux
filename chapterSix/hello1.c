/*
 * hello1.c
 * purpose	show the minimal calls needed to use curses
 * outline	initialize, draw stuff, wait for input, quit
 *
 * when complie, you should add lib -lcurses.
 */

#include <stdio.h>
#include <curses.h>

main()
{
	initscr();	/* turn on curses */
			/* send requests */
	clear();	/* clear screen */
	move(10,20);	/* row 10, col 20 */

	addstr("Hello, world");
			/* add a string */

	move(LINES -1, 0);
			/* move to LL */
	refresh();	/* update the screen */
	getch();	/* wait for user input */

	endwin();	/* turn off curses */
}



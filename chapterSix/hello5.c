/*
 * hello5.c
 * purpose bounce a message back and forth across the screen
 */

#include <stdio.h>
#include <curses.h>

#define LEFTEDGE	10
#define RIGHTEDGE	30
#define ROW		10

main()
{
	char *message = "Hello";//maybe is message[].
	char *blank   = "     ";//maybe is blank[].

	int dir = +1;
	int pos = LEFTEDGE;

	initscr(); /* start */

	clear();

	while(1){
		move(ROW, pos);
		addstr(message);	/* draw string */
		move(LINES -1, COLS -1);/* park the cursor */
		refresh();		/* show string */

		sleep(1);
		move(ROW, pos);		/* erase string */
		addstr(blank);		
		pos += dir;		/* advance position */

		if( pos >= RIGHTEDGE)	/* check for bounce */
			dir = -1;
		if( pos <= LEFTEDGE)
			dir = +1;
	}
}




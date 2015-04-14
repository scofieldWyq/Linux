/* showtty.c
 * display some current tty settings
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

main()
{
	struct termios ttyinfo;			/* struct hold tty info */
	if( tcgetattr(0, &ttyinfo) == -1)	/* get info */
	{
		perror("cannot get params about stdin");
		exit(1);
	}

	/* show info about tty */
	showbaud( cfgetospeed( &ttyinfo));	/* get + show baud rate */

	printf("The erase character is ascii %d, Ctrl - %c\n",
			ttyinfo.c_cc[VERASE], ttyinfo.c_cc[VERASE] - 1 + 'A');
	printf("The line kill character is ascii %d, Ctrl - %c\n",
			ttyinfo.c_cc[VKILL], ttyinfo.c_cc[VKILL] - 1 + 'A');
	show_some_flags( &ttyinfo);		/* show misc.flags */
}

showbaud( int the_speed)
/*
 * prints the speed in english
 */
{
	printf("the baud rate is ");
	switch( the_speed)
	{
		case B300:	printf("300\n");break;
		case B600:	printf("600\n");break;
		case B1200:	printf("1200\n");break;
		case B1800:	printf("1800\n");break;
		case B2400:	printf("2400\n");break;
		case B4800:	printf("4800\n");break;
		case B9600:	printf("9600\n");break;
		default:	printf("Fast\n");break;
	}
}

struct flaginfo { int fl_value; char *fl_name;};

struct flaginfo input_flags[] = {		/* c_iflag */
	IGNBRK, "Ignore break condition",
	BRKINT, "Signal interrupt on break",
	IGNPAR, "Ignore chars with parity errors",
	PARMRK, "Mark parity errors",
	INPCK,  "Enable input parity check",
	ISTRIP, "Strip character",
	INLCR,  "Map NL to CR on input",
	IGNCR,  "Ignore CR",
	ICRNL,  "Map CR to NL on input",
	IXON,   "Enable start/stop output control",
	/* _IXANY,"enable any char to restart output", */
	IXOFF,  "Enable start/stop input control",
	0,      NULL};

struct flaginfo local_flags[] = {		/* c_lflag */
	ISIG,  "Enable signals",
	ICANON,"Canonical input (erase and kill)",
	/* _XCASE, "Canonical upper/lower appearance", */
	ECHO,  "Enable echo",
	ECHOE, "Echo ERASE as BS-SPACE-BS",
	ECHOK, "Echo KILL by starting new line",
	0,      NULL};

show_some_flags( struct termios *ttyp)
/*
 * show the values of two of the flag sets_: c_iflag and c_lflag
 * adding c_oflag and c_cflag is pretty routine - just add new
 * tables above and a bit more code below.
 */
{
	show_flagset( ttyp->c_iflag, input_flags);
	show_flagset( ttyp->c_lflag, local_flags);
}

show_flagset( int the_value, struct flaginfo the_bit_names[])
/*
 * check each bit pattern and display descriptive title
 */
{
	int i;
	for( i=0; the_bit_names[i].fl_value ; i++)
	{
		printf( " %s is ", the_bit_names[i].fl_name);
		if( the_value & the_bit_names[i].fl_value)
			printf("ON\n");
		else
			printf("OFF\n");
	}
}


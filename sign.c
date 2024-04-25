#include "shell.h"
#include <signal.h>
/**
 * handle_sigint - Handle the sign entered
 * by the keyboard
 * @sign: Entry sign.
 */

void handle_sigint(int sign)

{
	printf("\n You have pressed Ctrl+C.\n");
	(void)sign;
}
/**
 * setup_signals - Handle the sign entered
 * by the keyboard
 */
void setup_signals(void)
{
	signal(SIGINT, handle_sigint);
}

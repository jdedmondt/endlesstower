/* commands.c: command handler functions */

#include <stdio.h>

#include "commands.h"

void quit(char **args)
{
	/* for now do nothing */
}

void help(char **args)
{
	for (int i = 0; i < N_CMDS; i++) {
		printf("%s : %s \n", CMDS[i].string, CMDS[i].desc);
	}
}

void info(char **args)
{
	printf("i am printing the information for the current environment.");
}

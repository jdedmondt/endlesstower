/* commands.c: command handler functions */

#include <stdio.h>
#include <string.h>

#include "commands.h"
#include "debug.h"

void quit(int argc, char **argv)
{
	/* for now do nothing */
}

void help(int argc, char **argv)
{
	for (int i = 0; i < N_CMDS; i++) {
		printf("%s : %s \n", CMDS[i].string, CMDS[i].desc);
	}
}

void info(int argc, char **argv)
{
	printf("i am printing the information for the current environment.");
}

void debug(int argc, char **argv)
{
	if (argc < 2) {
		printf("args bad matey\n");
		return;
	}

	if (!strcmp(argv[1], "p")) {
		printf("printing\n");
		debug_print();
	}

	if (!strcmp(argv[1], "a")) {
		printf("adding\n\n");
		if (argc != 4) { return; }
		debug_add(argv[2], argv[3]);
	}
}

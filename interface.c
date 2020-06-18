#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"

int interface_loop(void);
int process_input(char *input);

int process_input(char *input)
{
	int i;

	for (i = 0; i < N_CMDS; i++) {
		if (!strcmp(input, CMDS[i].string)) { /* see commands.h */
			char **args = NULL;
			
			CMDS[i].handler(args);
			
			return i;
		}
	}

	printf("entry not recognized\n");
	
	return i;
}

int interface_loop(void)
{
	/* in the future we need to display current location before $ */
	char *input = readline("$ ");

	int result = process_input(input);

	return result;
}

int main(void)
{
	int result = 1;
	while (result) {
		result = interface_loop();
	}
	return 0;
}

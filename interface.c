#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "game.h"
#include "debug.h"

int interface_loop(void);
int process_input(int argc, char **args);
char **tokenizer(char *string, int *argc);
char **append_str(char *str, int n, char **list, int list_size);

int process_input(int argc, char **argv)
{
	int i;

	for (i = 0; i < N_CMDS; i++) {
		if (!strcmp(argv[0], CMDS[i].string)) { /* see commands.h */

			CMDS[i].handler(argc, argv);

			return i;
		}
	}

	printf("entry not recognized\n");

	return i;
}

char **append_str(char *string, int nchars, char **list, int list_size)
{
	list = realloc(list, sizeof(char*)*(list_size+1));
	list[list_size] = malloc(strlen(string));
	strcpy(list[list_size], string);
	list[list_size][nchars] = '\0';

	return list;
}

char **tokenizer(char *input, int *argc)
{
	int start_idx = 0, end_idx = 0;
	int quotes = 0;
	int a = 0;

	char **output = malloc(sizeof(char*));

	/* strip leading, trailing whitespace */
	for (int i = strlen(input)-1; i >= 0 && (input[i] == ' ' || input[i] == '\t'); i--) {
		input[i] = '\0';
	}

	int i = 0;
	while (i < strlen(input) + 1) {
		switch (input[i]) {
		case '\0':
		case ' ':
			if (quotes) {
				break;
			}

			end_idx = i;
			output = append_str(input + start_idx, end_idx-start_idx, output, a);
			a++;
			start_idx = end_idx + 1;
			break;
		case '\"':
			if (quotes) {
				quotes = 0;
				end_idx = i;
				output = append_str(input + start_idx, end_idx-start_idx, output, a);
				a++;
				/* TODO: figure out a way to make this work if there isn't a space after the " */
				i++;
				start_idx = end_idx + 2;
				break;
			}
			quotes = 1;
			start_idx = i + 1;
			break;
		default:
			break;
		}
		i++;
	}

	*argc = a;
	return output;
}

int interface_loop(void)
{
	char *input = readline("$ ");
	int argc = 0;

	char **tokens = tokenizer(input, &argc);

	int result = process_input(argc, tokens);

	return result;
}

int main(void)
{
	int result = 1;

	init_game();

	if (DEBUG_BUILD) { debug_init(); }

	while (result) {
		result = interface_loop();
		putchar('\n');
	}
	return 0;
}

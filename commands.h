#ifndef COMMANDS_H
#define COMMANDS_H

/* command handler functions */

void quit(void *);
void help(void *);
void info(char **);

/* commands */
enum {
	QUIT = 0,	/* exit the program 			*/
	HELP,		/* print help information		*/
	INFO, 		/* print environment information 	*/
	N_CMDS,
};

struct cmd {
	int id;
	const char *string;
	const char *desc;
	int args;
	void (*handler)();
};

static struct cmd CMDS[] = {
	{QUIT, "quit", "exit the program ", 1, &quit},
	{HELP, "help", "print help information", 1, &help},
	{INFO, "info", "print environment information", 1, &info},
};

#endif

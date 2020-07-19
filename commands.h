#ifndef COMMANDS_H
#define COMMANDS_H

/* command handler functions */

void quit(int, char **);
void help(int, char **);
void info(int, char **);
void debug(int, char **);

/* commands */
enum {
	QUIT = 0,	/* exit the program 			*/
	HELP,		/* print help information		*/
	INFO, 		/* print environment information 	*/
	DEBUG,		/* use debug functions */
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
	{DEBUG, "debug", "use debug functions", 2, &debug},
};

#endif

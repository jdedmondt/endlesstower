#ifndef COMMANDS_H
#define COMMANDS_H

/* command handler functions */

void quit(int, char **);
void help(int, char **);
void info(int, char **);
void debug(int, char **);
void look(int, char **);
void travel(int, char **);
void go(int, char **);
void connect(int, char **);

/* commands */
enum {
	QUIT = 0,	/* exit the program 			*/
	HELP,		/* print help information		*/
	INFO, 		/* print environment information 	*/
	DEBUG,		/* use debug functions 			*/
	LOOK,		/* print current room info 		*/
	TRAVEL,		/* go up or down a floor in valid room	*/
	GO,		/* enter a door */
	CONNECT,	/* create a door */
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
	{DEBUG, "debug", "[cmd] [args], use debug functions (p, a, d, i)", 2, &debug},
	{LOOK, "look", "view current room", 1, &look},
	{TRAVEL, "travel", "[up/down], travel between floors in a valid room", 2, &travel},
	{GO, "go", "[door #], enter a door in the current room", 2, &go},
	{CONNECT, "connect", 
		  "[name] [dest id], create a new connection in the current room to specified room", 3, &connect},
};

#endif

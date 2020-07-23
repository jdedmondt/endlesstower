#ifndef COMMANDS_H
#define COMMANDS_H

/* command handler functions */

void quit(int, char **);
void help(int, char **);
void debug(int, char **);
void look(int, char **);
void travel(int, char **);
void go(int, char **);
void connect(int, char **);
void rooms(int, char **);
void mroom(int, char **);

/* commands */
enum {
	QUIT = 0,	/* exit the program 			*/
	HELP,		/* print help information		*/
	DEBUG,		/* use debug functions 			*/
	LOOK,		/* print current room info 		*/
	TRAVEL,		/* go up or down a floor in valid room	*/
	GO,		/* enter a door */
	CONNECT,	/* create a door */
	ROOMS,		/* list known rooms on floor */
	MROOM,		/* make a new room */
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
	{DEBUG, "debug", "[cmd] [args], use debug functions (p, a, d, i)", 2, &debug},
	{LOOK, "look", "view current room", 1, &look},
	{TRAVEL, "travel", "[up/down], travel between floors in a valid room", 2, &travel},
	{GO, "go", "[door #], enter a door in the current room", 2, &go},
	{CONNECT, "connect", 
		  "[name] [dest id], create a new connection in the current room to specified room", 3, &connect},
	{ROOMS, "rooms", "list known rooms on current floor", 1, &rooms},
	{MROOM, "mroom", "[name], make a new room on the current floor", 2, &mroom},
};

#endif

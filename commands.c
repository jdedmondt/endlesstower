/* commands.c: command handler functions */

#include <stdio.h>
#include <string.h>

#include "game.h"
#include "commands.h"
#include "debug.h"

void quit(int argc, char **argv)
{
	/* for now do nothing */
}

void help(int argc, char **argv)
{
	for (int i = 0; i < N_CMDS; i++) {
		printf("%s\t: %s \n", CMDS[i].string, CMDS[i].desc);
	}
}

void info(int argc, char **argv)
{
	printf("i am printing the information for the current environment.");
}

void debug(int argc, char **argv)
{
	if (argc < 2) {
		printf("args bad matey (p, a, d)\n");
		return;
	}

	if (!strcmp(argv[1], "p")) {
		printf("printing\n");
		debug_print();
	}

	if (!strcmp(argv[1], "a")) {
		printf("adding\n\n");
		if (argc != 4) { return; }
		debug_add_room(argv[2], argv[3]);
	}

	if (!strcmp(argv[1], "d")) {
		debug_print_desc();
	}

	if (!strcmp(argv[1], "i")) {
		debug_print_info();
	}

	if (!strcmp(argv[1], "af")) {
		if (argc != 3) { return; }
		debug_add_floor(argv[2]);
	}
}

void look(int argc, char **argv) {
	printf("%s (Floor %d -- %s)\n\n", G.current_room->name, G.current_floor->num, G.current_floor->name);
	printf("%s\n\n", G.current_room->desc);

	printf("Connections:\n");
	for (int i = 0; i < G.current_room->n_doors; i++) {
		printf("%d: %s\n", i, G.current_room->door_list[i]->name);
	}
	putchar('\n');
}

void travel(int argc, char **argv) {
	if (argc != 2) {
		printf("no direction provided\n");
		return;
	}

	if (!strcmp(argv[1], "up") && G.current_floor->up != NULL) {
		G.current_floor = G.current_floor->up;
		G.current_room = G.current_floor->root_room;
		printf("You call the elevator and press the button for floor %d\n",
		       G.current_floor->num);
	}

	if (!strcmp(argv[1], "down") && G.current_floor->down != NULL) {
		G.current_floor = G.current_floor->down;
		G.current_room = G.current_floor->root_room;
		printf("You call the elevator and press the button for floor %d\n",
			G.current_floor->num);
	}
}

#include "game.h"

#include <stdio.h>
#include <stdlib.h>

void debug_init(void) {
	append_room(new_room("gachi", "gasm"), world->ground_floor);
}

void debug_print(void) {
	printf("rooms: \n");

	for (int i = 0; i < world->ground_floor->n_rooms; i++) {
		printf("%s\n", world->ground_floor->room_list[i]->name);
	}
}

void debug_add(char *name, char *desc) {
	append_room(new_room(name, desc), world->ground_floor);
}

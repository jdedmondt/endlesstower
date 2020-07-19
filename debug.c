#include "game.h"

#include <stdio.h>
#include <stdlib.h>

void debug_init(void) {
	append_room(new_room("gachi", "gasm"));
}

void debug_print(void) {
	printf("rooms: \n");

	for (int i = 0; i < n_rooms; i++) {
		printf("%s\n", room_list_master[i]->name);
	}
}

void debug_add(char *name, char *desc) {
	append_room(new_room(name, desc));
}

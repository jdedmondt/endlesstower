/* game.c */

#include "game.h"

#include <string.h>
#include <stdlib.h>

void init_world(void) {
	n_rooms = 0;
}


Room *new_room(char *name, char *desc) {
	Room *new_room = malloc(sizeof(Room));

	new_room->name = strdup(name);
	new_room->desc = strdup(desc);

	new_room->door_list = NULL;

	return new_room;
}

void append_room(Room *room) {
	room_list_master = realloc(room_list_master, sizeof(Room *) *(n_rooms + 1));
	room_list_master[n_rooms++] = room;
}

Door *new_door(char *name, Room *origin, Room *dest) {
	Door *new_door = malloc(sizeof(Door));

	new_door->name = strdup(name);

	new_door->origin = origin;
	new_door->dest = dest;

	return new_door;
}

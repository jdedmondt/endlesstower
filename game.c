/* game.c */

#include "game.h"

#include <string.h>
#include <stdlib.h>

void init_game(void) {
	G.worldspace = create_world();
	G.current_floor = G.worldspace->ground_floor;
	G.current_room = G.current_floor->root_room;
}

World *create_world(void) {
	World *new_world = malloc(sizeof(World));
	new_world->ground_floor = new_floor("Ground Floor");
	new_world->n_floors = 1;
}

Floor *new_floor(char *name) {
	Floor *new_floor = malloc(sizeof(Floor));

	new_floor->name = strdup(name);
	new_floor->up = NULL;
	new_floor->down = NULL;
	new_floor->root_room = new_room("Lobby", DEFAULT_LOBBY_DESC);
	new_floor->room_list = NULL;
	new_floor->n_rooms = 0;
	append_room(new_floor->root_room, new_floor);

	return new_floor;
}

void add_floor(Floor *floor, World *world, int dir) {
	Floor *temp = world->ground_floor;
	if (dir == 1) {
		while (temp->up != NULL) {
			temp = temp->up;
		}
		temp->up = floor;
		floor->down = temp;
	} else {
		while (temp->down != NULL) {
			temp = temp->down;
		}
		temp->down = floor;
		floor->up = temp;
	}
	world->n_floors++;
}

Room *new_room(char *name, char *desc) {
	Room *new_room = malloc(sizeof(Room));

	new_room->name = strdup(name);
	new_room->desc = strdup(desc);
	new_room->id = 0;

	new_room->door_list = NULL;

	return new_room;
}

void append_room(Room *room, Floor *floor) {
	floor->room_list = realloc(floor->room_list, sizeof(Room *) *(floor->n_rooms + 1));
	floor->room_list[floor->n_rooms++] = room;
}

Door *new_door(char *name, Room *origin, Room *dest) {
	Door *new_door = malloc(sizeof(Door));

	new_door->name = strdup(name);

	new_door->origin = origin;
	new_door->dest = dest;

	return new_door;
}

#include "game.h"

#include <stdio.h>
#include <stdlib.h>

World *world;

void debug_init(void) {
	world = G.worldspace;
	append_room(new_room("gachi", "gasm"), world->ground_floor);

	add_door(new_door("Wooden Door", G.current_room, G.current_floor->room_list[1]), G.current_room);
}

void debug_print(void) {
	printf("rooms: \n");

	for (int i = 0; i < G.current_floor->n_rooms; i++) {
		printf("%s\n", G.current_floor->room_list[i]->name);
	}
}

void debug_add_room(char *name, char *desc) {
	append_room(new_room(name, desc), G.current_floor);
}

void debug_print_desc(void) {
	printf("%s\n", G.current_room->desc);
}

void debug_print_info(void) {
	printf("floor: %s (%d)\n", G.current_floor->name, G.current_floor->num);
	printf("room: %s\n", G.current_room->name);
	printf("desc:\n%s\n", G.current_room->desc);
	printf("doors:\n");
	for (int i = 0; i < G.current_room->n_doors; i++) {
		printf("%s (dest: \"%s\")\n", G.current_room->door_list[i]->name,
				    G.current_room->door_list[i]->dest->name);
	}
}

void debug_add_floor(char *name) {
	Floor *temp = new_floor(name);
	add_floor(temp, G.worldspace, 1);
}

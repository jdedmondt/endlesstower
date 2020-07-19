/* game.h */

#ifndef GAME_H
#define GAME_H


#define DEBUG_BUILD 1


struct Room;
struct Door;


/* object structs */

typedef struct Room {
	char *name;
	char *desc;

	struct Door *door_list;
} Room;

typedef struct Door {
	char *name;

	struct Room *dest;
	struct Room *origin;
} Door;

/* function declarations */

void init_world(void);
Room *new_room(char *name, char *desc);
void append_room(Room *room);
Door *new_door(char *name, Room *origin, Room *dest);

/* globals */

Room **room_list_master;
int n_rooms;

#endif

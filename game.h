/* game.h */

#ifndef GAME_H
#define GAME_H


#define DEBUG_BUILD 1

struct Gamestate;

struct World;
struct Floor;
struct Room;
struct Door;


/* object structs */

struct Gamestate {
	struct World *worldspace;
	struct Floor *current_floor;
	struct Room *current_room;
};

typedef struct World {
	struct Floor *ground_floor;
	int n_floors;
} World;

typedef struct Floor {
	char *name;

	struct Floor *up;
	struct Floor *down;
	struct Room *root_room;
	struct Room **room_list;
	int n_rooms;
} Floor;

typedef struct Room {
	char *name;
	char *desc;
	int id;

	struct Door *door_list;
} Room;

typedef struct Door {
	char *name;

	struct Room *dest;
	struct Room *origin;
} Door;

/* function declarations */

void init_game(void);
World *create_world(void);
Floor *new_floor(char *name);
void add_floor(Floor *floor, World *world, int dir);
Room *new_room(char *name, char *desc);
void append_room(Room *room, Floor *floor);
Door *new_door(char *name, Room *origin, Room *dest);

/* globals */

struct Gamestate G;

#endif

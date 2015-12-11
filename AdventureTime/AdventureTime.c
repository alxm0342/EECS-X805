/*
Name: Alexis Mendez
Class: UCI UnEx - EECS X805 - Western Digital
Assignment: Topic 4 - "Adventure Time"
Date: 9/16/2014
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define DUNGEON_SIZE 3
#define DESCRIPTION_SIZE 100

//start in the center of the dungeon
#define STARTING_POSITION 1

typedef struct room
{
	char *description;
	struct room *northroom;
	struct room *southroom;
} room;

struct room *all_rooms[DUNGEON_SIZE];
struct room southern, center, northern;
int nextAvailableRoom = 0;
int currentPosition = 0;

void setRoom(room *room_p, char roomDescription[DESCRIPTION_SIZE], room *north_p, room *south_p) {
	if (nextAvailableRoom < DUNGEON_SIZE) {
		room_p->description = roomDescription;
		room_p->northroom = north_p;
		room_p->southroom = south_p;
		all_rooms[nextAvailableRoom] = room_p;
		nextAvailableRoom++;
	}
	else {
		printf("Cannot add more rooms, the dungeon is full.\n");
	}
}

void InitDungeon() {
	setRoom(&southern, "This is the southern-most room.", &center, 0);
	setRoom(&center, "This is the center of the dungeon.", &northern, &southern);
	setRoom(&northern, "This is the northern-most room.", 0, &center);
	currentPosition = STARTING_POSITION;
}

int stringsAreEqual(char *str1, char *str2)
{
	int index;
	int length = sizeof(str1)/sizeof(char);

	int sz1 = sizeof(str1);
	int sz2 = sizeof(str2);

	if (sizeof(str1) != sizeof(str2)) {
		return 0;
	}

    for (index = 0; index < length; index++) {
        int difference = toLower(str1[index]) - toLower(str2[index]);
        if (difference != 0 || (!*str1 && *str2))
            return 0;
    }

	return 1;
}

int toLower (char c) {
	return (c > 96) ? c : (c + 32);
}

void doCommand(char *cmd) {
	struct room *roomAfterCommand;

	if (stringsAreEqual(cmd, "LOOK")) {
		//command is valid, do not change position
	}
	else if (stringsAreEqual(cmd, "NORTH")) {
		if (all_rooms[currentPosition]->northroom != 0) {
			currentPosition++;
		}
		else {
			printf("You can't go there.\n\n");
			return;
		}
	}
	else if (stringsAreEqual(cmd, "SOUTH")) {
		if (all_rooms[currentPosition]->southroom != 0) {
			currentPosition--;
		}
		else {
			printf("You can't go there.\n\n");
			return;
		}
	}
	else if (stringsAreEqual(cmd, "QUIT")) {
		printf("Goodbye!\n\n");
		return;
	}
	else {
		printf("Invalid command.\n\n");
		return;
	}

	roomAfterCommand = all_rooms[currentPosition];
	printf("%s\n\n", roomAfterCommand->description);
}

main()
{
	char command[10];

	InitDungeon();

	while (TRUE) {
		printf("Enter a command: ");
		scanf("%s", command);
		doCommand(command);

		if (stringsAreEqual(command, "QUIT")) {
			break;
		}
	}

	//clear newline from input buffer
	getchar();
	
	//pause before exiting
	printf("Press any key to exit...\n");
	getchar();

    return;
}
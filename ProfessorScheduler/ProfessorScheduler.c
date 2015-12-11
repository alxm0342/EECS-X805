/*
Name: Alexis Mendez
Class: UCI UnEx - EECS X805 - Western Digital
Assignment: Topic 3 - "Professor Scheduler"
Date: 9/09/2014
*/

#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define DB_SIZE 1024
#define MAX_NAME_LENGTH 256

typedef struct record
{
	char *name;
	char schedule;
} record;

struct record db[DB_SIZE];
int nextAvailableIndex = 0;

int recordIndex(char * nameToCheck)
{
	int index = 0;
	for (index = 0; index < DB_SIZE; index++)
	{
		if ((index < nextAvailableIndex) && (db[index].name == nameToCheck))
		{
			return index;
		}
		else
		{
			return -1;
		}
	}
}

int getCommandValue(char * cmd)
{
	const char * ADD = "ADD";
	const char * DELETE = "DELETE";
	const char * LIST = "LIST";
	const char * QUIT = "QUIT";

	if (*cmd == *ADD)
	{
		return 1;
	}
	else if (*cmd == *DELETE)
	{
		return 2;
	}
	else if (*cmd == *LIST)
	{
		return 3;
	}
	else if (*cmd == *QUIT)
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

int getDayValue(char * day)
{
	const char * SUNDAY = "SUNDAY";
	const char * MONDAY = "MONDAY";
	const char * TUESDAY = "TUESDAY";
	const char * WEDNESDAY = "WEDNESDAY";
	const char * THURSDAY = "THURSDAY";
	const char * FRIDAY = "FRIDAY";
	const char * SATURDAY = "SATURDAY";

	if (*day == *SUNDAY)
	{
		return 1;
	}
	else if (*day == *MONDAY)
	{
		return 2;
	}
	else if (*day == *TUESDAY)
	{
		return 3;
	}
	else if (*day == *WEDNESDAY)
	{
		return 4;
	}
	else if (*day == *THURSDAY)
	{
		return 5;
	}
	else if (*day == *FRIDAY)
	{
		return 6;
	}
	else if (*day == *SATURDAY)
	{
		return 7;
	}
	else
	{
		return 0;
	}
}

int check_bit(char schedule, int index)
{
	return (schedule & (1 << (index)));
}

void changeSchedule(record * recordToChange, int cmd, int dayValue)
{
	if (cmd == 1)
	{
		recordToChange->schedule |= (1 << dayValue);
	}
	else if (cmd == 2)
	{
		recordToChange->schedule &= ~(1 << dayValue);
	}
}

void * listSchedule(char * schedule, char * scheduleString)
{
	int bitIndex = 0;

	if (check_bit(*schedule, 1))
	{
		strcat(scheduleString, "SUNDAY, ");
	}
	if (check_bit(*schedule, 2))
	{
		strcat(scheduleString, "MONDAY, ");
	}
	if (check_bit(*schedule, 3))
	{
		strcat(scheduleString, "TUESDAY, ");
	}
	if (check_bit(*schedule, 4))
	{
		strcat(scheduleString, "WEDNESDAY, ");
	}
	if (check_bit(*schedule, 5))
	{
		strcat(scheduleString, "THURSDAY, ");
	}
	if (check_bit(*schedule, 6))
	{
		strcat(scheduleString, "FRIDAY, ");
	}
	if (check_bit(*schedule, 7))
	{
		strcat(scheduleString, "SATURDAY, ");
	}
}

main()
{
	int initialized = 0;
	char cmd[256];
	char arg1[10];
	char arg2[10];

	while (TRUE)
	{
		//record record_p;
		char *initial = "";
		int commandValue = 0;
		int dayValue = 0;
		int foundIndex = 0;

		printf("Enter a command: ");
		scanf("%s%s%s", cmd, arg1, arg2);

		//check command
		commandValue = getCommandValue(cmd);

		//validate command
		if (commandValue == 0)
		{
			printf("Invalid Command, please re-enter\n");
			continue;
		}
		else if(commandValue == 4)
		{
			printf("Goodbye!");
			return;
		}

		//validate name, find correct index to modify
		foundIndex = recordIndex(arg1);
		if (foundIndex == -1)
		{
			 foundIndex = nextAvailableIndex;
			 nextAvailableIndex++;
		}

		//write name attribute of record
		db[foundIndex].name = arg1;

		//LIST command only
		if (commandValue == 3)
		{
			char thisSchedule[100] = "";
			listSchedule(&db[foundIndex].schedule, thisSchedule);
			printf("%s\n\n", thisSchedule);
			continue;
		}

		//validate day
		dayValue = getDayValue(arg2);
		switch (dayValue)
		{
			case 0:
				printf("Invalid day, please re-enter command\n");
				continue;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				changeSchedule(&db[foundIndex], commandValue, dayValue);
				printf("Database Modified: %s %s %s\n\n", cmd, arg1, arg2);
				break;
		}
	}

	//clear newline from input buffer
	getchar();
	
	//pause before exiting
	printf("\nPress any key to exit...\n");
	getchar();

    return;
}
/*
Name: Alexis Mendez
Class: UCI UnEx - EECS X805 - Western Digital
Assignment: Topic 1 - "Get And Put"
Date: 8/25/2014
*/

#include <stdio.h>

main()
{
    char name[256];

	//get input
	printf("What is your name? ");
    scanf("%s", name);

	//display
	printf("\nHi, %s!", name);

	//clear newline from input buffer
	getchar();

	//pause before exiting
	printf("\n\nPress any key to exit...\n");
	getchar();

    return;
}
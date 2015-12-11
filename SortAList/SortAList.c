/*
Name: Alexis Mendez
Class: UCI UnEx - EECS X805 - Western Digital
Assignment: Topic 2 - "Sort A List"
Date: 9/02/2014
*/

#include <stdio.h>

#define LIST_SIZE 3
#define NEW_LINE 10
#define SPACE 32
#define INTEGER_OFFSET 48

main()
{
    int unsortedList[LIST_SIZE];
	int sortedList[LIST_SIZE];
	char used[LIST_SIZE] = {0, 0, 0};
	int temp = 0;
	int unsortedIndex = 0;
	int sortedIndex = 0;
	int usedIndex = 0;

	//get input
	printf("Input 3 numbers: ");
    while (unsortedIndex < LIST_SIZE)
    {
		scanf("%d", &temp);
		unsortedList[unsortedIndex] = temp;
		unsortedIndex++;
    }

	//sort list
	while (sortedIndex < LIST_SIZE) {
		int minIndex = -1;
		for (unsortedIndex = 0; unsortedIndex < LIST_SIZE; unsortedIndex++) {
			if (!used[unsortedIndex] && ((minIndex < 0) || (unsortedList[minIndex] > unsortedList[unsortedIndex]))) {
				minIndex = unsortedIndex;
			}
		}
		sortedList[sortedIndex] = unsortedList[minIndex];
		used[minIndex] = 1;
		sortedIndex++;
	}

	//display list
	printf("\nSorted: ");
	for (sortedIndex = 0; sortedIndex < LIST_SIZE; sortedIndex++)
	{
		printf("%d ", sortedList[sortedIndex]);
	}

	//clear newline from input buffer
	getchar();

	//pause before exiting
	printf("\n\nPress any key to exit...\n");
	getchar();

    return;
}
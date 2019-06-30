#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"
void menu(LinkedList* lst) {
	int stay = 1;
	int selection;
	do
	{
		printf("\n______________________________________________________________________________________\n");
		printf("|Option Number|                            Description                               |\n");
		printf("|_______________|____________________________________________________________________|\n");
		printf("|       1       |Print current patients                                             |\n");
		printf("|       2       |Add new patient                                                    |\n");
		printf("|       3       |Remove patient                                                     |\n");
		printf("|       4       |Create file with current employee list                              |\n");
		printf("|       0       |Exit program                                                        |\n");
		printf("|_______________|____________________________________________________________________|\n");
		printf("\nWhat do you want to do?\n\n");

		scanf("%d", &selection);
		getchar();

		switch (selection)
		{
		case 0:
			//free allocated memory end terminate program
			FreeMemoryAllocated(lst);
			stay = 0;
			break;
		case 1:
			PrintAllRecords(lst);
			break;
		case 2:
			AddRecord(lst);
			break;
		case 3:
			RemoveRecord(lst);
			break;
		case 4:
			
			break;

		default:
			printf("\nERROR: You did not enter a valid input. Please try again.\n\n");
			break;
		}

	} while (stay != 0);
}

int main(void) {

	LinkedList* l = CreateList();
	menu(l);
	return 0;
}
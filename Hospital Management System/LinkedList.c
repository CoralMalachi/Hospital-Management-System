#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"

char* read_line(char* line)
{
	int c;
	line = malloc(sizeof(char));
	//checking if allocation was successful or not
	if (line == NULL)
	{
		printf("%s\n", "Allocation failed");
		exit(1);
	}

	/*
	unsigned type might be seen used as loop variable as loop variables
	are typically greater than or equal to 0
	*/

	size_t i = 0;
	while ((c = getchar()) != '\n' && c != EOF)
	{
		//type casting `int` to `char`, since getchar return int
		line[i] = (char)c;
		i++;
		line = realloc(line, (i + 1) * sizeof(char));
		if (line == NULL) {
			printf("%s\n", "Reallocation failed");
			exit(1);
		}
	}
	//inserting null character at the end
	line[i] = '\0';
	return line;

}
void PrintPatientDetails(patient_node* p)
{
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("patient name: %s \n", p->first_name);
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

}
char* copyString(char* name)
{
	char* s = malloc(strlen(name) + 1);
	if (s != NULL) {
		strcpy(s, name);
	}
	return s;
}

LinkedList* CreateList()
{
	LinkedList* l = malloc(sizeof(LinkedList));
	
	l->head = NULL;
	return l;
}

patient_node* CreateNode()
{
	static int count = 0;
	patient_node* n = malloc(sizeof(patient_node));
	printf("Enter first name of new patient: ");
	/*char* name = NULL;
	name = read_string(name);
	n->first_name = copyString(name);
	free(name);*/
	n->first_name = NULL;
	n->first_name = read_string(n->first_name);
	if (n->first_name == NULL) {
		printf("first name can not be empty!\n");
		return NULL;
	}

	printf("Enter last name of new patient: ");
	n->last_name = NULL;
	n->last_name = read_string(n->last_name);
	if (n->last_name == NULL) {
		printf("first name can not be empty!\n");
		return NULL;
	}


	n->next = NULL;
	count++;
	n->number = count; 
	return n;
}

patient_node* SearchNodeByNumber(LinkedList* lst, int count)
{
	if (lst->head == NULL)
	{
		//list is empty
		printf("patient not in list, since list is EMPTY!! \n");
		return NULL;
	}
	else
	{
		patient_node* cure = lst->head;
		while (cure)
		{
			if (cure->number == count)
				return cure;
		}
		//if we reached here that means the node is not in list
		printf("patient not in list\n");
		return NULL;
	}
}

patient_node* SearchName(LinkedList* lst, char* first, char* last)
{
	if (lst->head == NULL)
	{
		//list is empty
		printf("patient not in list, since list is EMPTY!! \n");
		return NULL;
	}
	else
	{
		patient_node* cure = lst->head;
		while (cure)
		{
			if (strcmp(first, cure->first_name) == 0) {
				if (strcmp(last, cure->last_name) == 0) {
					return cure;
				}
			}
		}
		//if we reached here that means the node is not in list
		printf("\nSorry. patient not in list\n");
		return NULL;
	}
}



char* read_string(char* line)
{
	int c;
	line = malloc(sizeof(char));
	//checking if allocation was successful or not
	if (line == NULL)
	{
		printf("%s\n", "Allocation failed");
		exit(1);
	}

	/*
	unsigned type might be seen used as loop variable as loop variables
	are typically greater than or equal to 0
	*/

	size_t i = 0;
	while ((c = getchar()) != '\n' && c != EOF && c !=' ')
	{
		//type casting `int` to `char`, since getchar return int
		line[i] = (char)c;
		i++;
		line = realloc(line, (i + 1) * sizeof(char));
		if (line == NULL) {
			printf("%s\n", "Reallocation failed");
			exit(1);
		}
	}
	//inserting null character at the end
	line[i] = '\0';
	if (i == 0)
		return NULL;
	return line;
}

void RemoveRecord(LinkedList* lst)
{
	printf("Enter first name of the patient you want to delete: ");
	char* first = NULL;
	first = read_string(first);
	printf("Enter last name of the patient you want to delete: ");
	char* last = NULL;
	last = read_string(last);

	if (lst->head == NULL)
	{
		//list is empty
		printf("patient not in list, since list is EMPTY!! \n");
		free(last);
		free(first);
		return;
	}
	else
	{
		patient_node* root = lst->head;
		patient_node* prev = NULL;
		patient_node* cure = lst->head;
		while (cure)
		{
			if (strcmp(first, cure->first_name) == 0) {
				if (strcmp(last, cure->last_name) == 0) 
				{
					//if cure is head
					if (prev==NULL)
					{
						//set next node as head
						patient_node* new_head = cure->next;
						lst->head = new_head;
					}
					else {
						//Delete the node:
						prev->next = cure->next;
					}
					
					free(cure->first_name);
					free(cure->last_name);
					cure->last_name = NULL;
					cure->first_name = NULL;
					free(first);
					free(last);
					free(cure);
					cure = NULL;
					last = NULL;
					first = NULL;	
					printf("\n node have been deleted\n");
					return;
				}
			}
			prev = cure;
			cure = cure->next;
		}
		//if we reached here that means the node is not in list
		printf("\nSorry. patient not in list\n");
		
	}

}

void AddRecord(LinkedList* lst)
{
	patient_node* n = CreateNode();
	if (n == NULL) {
		printf("You entered invalid input. Insert did not occur.\n ");		
	}
	else
	{
		lst->head = PushNode(lst->head, n);
	}	
}

void PrintAllRecords(LinkedList* lst)
{
	if (lst->head == NULL) {
		printf("The list is empty!! \n\n");
	}
	else
	{
		patient_node* cure = lst->head;
		while (cure)
		{
			PrintPatientDetails(cure);
			cure = cure->next;
		}
	}
}

void FreeMemoryAllocated(LinkedList* lst)
{
	_freeAllNodes(&(lst->head));
	free(lst);
}

/*
Function to push node to the end of list
*/
patient_node* PushNode(patient_node* head, patient_node* toAdd)
{
	//if the list is empty, make the new node the head of list
	if (head == NULL) {
		return toAdd;
	}
	patient_node* cure = head;
	while (cure->next)
	{
		cure = cure->next;
	}
	cure->next = toAdd;
	return head;
}


void _freeAllNodes(patient_node** node_ref)
{
	freeAllNodes(*node_ref);
	//set root to nul
	*node_ref = NULL;
}

void freeAllNodes(patient_node* node)
{
	if (node == NULL)
		return;
	freeAllNodes(node->next);
	free(node->first_name);
	free(node->last_name);
	free(node);
}

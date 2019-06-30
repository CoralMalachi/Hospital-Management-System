#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct node_t
{
	int number;
	char* first_name;
	char* last_name;
	char* address_line;
	unsigned int age;
	char* disease_description;
	unsigned int room_number;
	struct node_t* next;
}patient_node;

void PrintPatientDetails(patient_node* p);

typedef struct LinkedList_t
{
	patient_node* head;
}LinkedList;

char* copyString(char* name);


LinkedList* CreateList();
patient_node* CreateNode();

patient_node* SearchNodeByNumber(LinkedList* lst, int count);
patient_node* SearchName(LinkedList* lst, char* first,char* last);

char* read_line(char* line);
char* read_string(char* line);

/*
@@@@@@@@@@@@@ MENU OPTIONS @@@@@@@@@@@@@@
*/
void RemoveRecord(LinkedList* lst);
void AddRecord(LinkedList* lst);
void PrintAllRecords(LinkedList* lst);
void FreeMemoryAllocated(LinkedList* lst);


void _freeAllNodes(patient_node** node_ref);
void freeAllNodes(patient_node* node);

patient_node* PushNode(patient_node* head, patient_node* toAdd);


#endif
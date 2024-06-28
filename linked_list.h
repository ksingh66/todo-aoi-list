#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct linked_list // Basic linked list
{//Our linked list has two attributes, a string 20 chars long named "element" and a pointer to the next item in the list
    char element[20]; 
    struct linked_list *next_element_address; // pointer name is "next_element_address" and the pointer type is the linked_list structure
};
typedef struct linked_list node; //This line makes it so we can easily declare nodes in our linked list (See the line right after main())
 
void print_linked_list(node *head);
void linked_list_add(node **head, const char *new_element, int index);
void linked_list_remove(node **head, int index);
void make_head(node **head, const char *task);
void linked_list_modify(node **head, int index1, int index2);
#endif // LINKED_LIST_H

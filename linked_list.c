//linked_list.c
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>  

void print_linked_list(node *head){ //This function is to print all items in the linked list in the right order
    node *current_pointer = head; // This line creates a temp pointer which we use to print each element, We use temp pointer so that we do not change the head 
    while (current_pointer != NULL){ // We start with the head and work our way down to the last pointer which will be NULL
        printf("%s\n",current_pointer->element); //This line prints the element at the current pointer
        current_pointer = current_pointer->next_element_address; // Now we increment the current pointer into the next pointer
    }//When we assign the items in the list values we will have one of those items have a pointer to NULL.
}

void make_head(node **head){ //This function is to be used to make the first node 
    node *new_node= malloc(sizeof(node)); 
    new_node->next_element_address = NULL;
    *head = new_node;
}

void linked_list_add(node **head,const char *new_element, int index){ //We start by having three inputs, address of head , 
//the element (task) we want to put and the index at which we want to put it
    node *new_node= malloc(sizeof(node)); //here we dynamically allocate space for the data type "node" and we make it for 1 node.
    // If we wanted more than one node we would do "malloc(sizeof(2,node))"
    
    strcpy(new_node->element,new_element); //this line makes element at new node the new_element that was inputted into the function.

    if (index == 0){ // If insert at index 0 we set the address of the new element as the new head and attach the old head to the tail of our new element
        new_node->next_element_address = *head;
        *head = new_node;
        return;
    }
    else{
        node *current_pointer = *head; 
        for (int count = 0;count<index-1 &&current_pointer != NULL;++count){
            current_pointer = current_pointer->next_element_address;
        }
        if (current_pointer == NULL) {
            printf("Index out of bounds\n");
            free(new_node);
            return;
            }
        new_node->next_element_address = current_pointer->next_element_address; 
        current_pointer->next_element_address = new_node;

    }

}


void linked_list_remove(node **head, int index){
    node *pointer_before_index = *head;
    node *old_head = *head;
    if (index == 0) {
        *head = (*head)->next_element_address;
        free(old_head);
    }
    else{
    for (int count = 0;count<index-1 &&pointer_before_index != NULL;++count){
            pointer_before_index = pointer_before_index->next_element_address;
    }
    node *node_to_del = pointer_before_index->next_element_address;
    pointer_before_index->next_element_address = node_to_del->next_element_address;
    free(node_to_del);}
}

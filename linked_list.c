//linked_list.c
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>  

void print_linked_list(node *head){ //This function is to print all items in the linked list in the right order
    node *current_pointer = head; // This line creates a temp pointer which we use to print each element, We use temp pointer so that we do not change the head 
    int entry_value = 1;
    while (current_pointer != NULL){ // We start with the head and work our way down to the last pointer which will be NULL
        printf(" %d. %s\n", entry_value, current_pointer->element); //This line prints the element at the current pointer
        current_pointer = current_pointer->next_element_address; // Now we increment the current pointer into the next pointer
        entry_value = entry_value + 1;
    }//When we assign the items in the list values we will have one of those items have a pointer to NULL.
}

void make_head(node **head, const char *task){ //This function is to be used to make the first node 
    node *new_node= malloc(sizeof(node)); 
    new_node->next_element_address = NULL;
    strcpy(new_node->element, task);
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

void linked_list_modify(node **head, int index1, int index2) {
    node *prior_node = NULL, *prior_node2 = NULL;
    node *index_1 = *head, *index_2 = *head;

    for (int i = 0; index_1 != NULL && i < index1; ++i) {
        prior_node = index_1;
        index_1 = index_1->next_element_address;
    }

    for (int i = 0; index_2 != NULL && i < index2; ++i) {
        prior_node2 = index_2;
        index_2 = index_2->next_element_address;
    }
//the edge case is confusing, I asked gpt to explain it to me and I still dont get it
    if (prior_node != NULL) {
        prior_node->next_element_address = index_2;
    } else {
        *head = index_2;
    }

    if (prior_node2 != NULL) {
        prior_node2->next_element_address = index_1;
    } else {
        *head = index_1;
    }

    node *temp = index_1->next_element_address;
    index_1->next_element_address = index_2->next_element_address;
    index_2->next_element_address = temp;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>  

struct linked_list // Basic linked list
{//Our linked list has two attributes, a string 20 chars long named "element" and a pointer to the next item in the list
    char element[20]; 
    struct linked_list *next_element_address; // pointer name is "next_element_address" and the pointer type is the linked_list structure
};
typedef struct linked_list node; //This line makes it so we can easily declare nodes in our linked list (See line 19)
 
void print_linked_list(node *head){ //This function is to print all items in the linked list in the right order
    node *current_pointer = head; // This line creates a temp pointer which we use to print each element, We use temp pointer so that we do not change the head 
    while (current_pointer != NULL){ // We start with the head and work our way down to the last pointer which will be NULL
        printf("%s ->",current_pointer->element); //This line prints the element at the current pointer
        current_pointer = current_pointer->next_element_address; // Now we increment the current pointer into the next pointer
    }//When we assign the items in the list values we will have one of those items have a pointer to NULL.
}
int main(){
    node node1, node2, node3, node4;//Declares 4 nodes
    node *head;//makes a pointer of type "node"/"linked list"

    //here we use strcpy to give each element of each node a value(to do task)
    strcpy(node1.element, "study test");
    strcpy(node2.element, "do hw");
    strcpy(node3.element, "exercise");
    strcpy(node4.element, "read book");
//Now we start assigning the order in which we want the linked list to work
    head = &node1;//This line initializes a head node so that our linked_list related functions know where to start from
//note that the node name has nothing to do with the order and that only the address that is assigned determines the order
    node1.next_element_address = &node2;
    node2.next_element_address = &node3;
    node3.next_element_address = &node4;
    node4.next_element_address = NULL; //node 4 marks the final node in our linked list

    print_linked_list(head);
}//TO ADD FEATURES
// Include two functions one to add items at a specific point in the list and one to remove item at a specific point in the list
//linked_list_add()
//linked_list_remove()
// also in the future add a funcitons that can replace the index of two items.
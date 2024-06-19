#include <stdlib.h>
#include <stdio.h>
#include <string.h>  

struct linked_list // Basic linked list
{//Our linked list has two attributes, a string 20 chars long named "element" and a pointer to the next item in the list
    char element[20]; 
    struct linked_list *next_element_address; // pointer name is "next_element_address" and the pointer type is the linked_list structure
};
typedef struct linked_list node; //This line makes it so we can easily declare nodes in our linked list (See the line right after main())
 
void print_linked_list(node *head){ //This function is to print all items in the linked list in the right order
    node *current_pointer = head; // This line creates a temp pointer which we use to print each element, We use temp pointer so that we do not change the head 
    while (current_pointer != NULL){ // We start with the head and work our way down to the last pointer which will be NULL
        printf("%s ->\n",current_pointer->element); //This line prints the element at the current pointer
        current_pointer = current_pointer->next_element_address; // Now we increment the current pointer into the next pointer
    }//When we assign the items in the list values we will have one of those items have a pointer to NULL.
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
    for (int count = 0;count<index-1 &&pointer_before_index != NULL;++count){
            pointer_before_index = pointer_before_index->next_element_address;
    }
    node *node_to_del = pointer_before_index->next_element_address;
    pointer_before_index->next_element_address = node_to_del->next_element_address;
    free(node_to_del);
    
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
    char task[] = "cry very loudly";
    char *taskp = task;
    print_linked_list(head); //here we just print our list
    printf("\n");
    linked_list_add(&head,taskp,3);
    print_linked_list(head);
    printf("\n");
    linked_list_remove(&head,0);
    print_linked_list(head);

}
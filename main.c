#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

#include "linked_list.h"

int prompt_user(){
    int user_input;
    printf("Enter the corresponding number for the action you want to perform:\n");
    printf("1. Add a new task\n");
    printf("2. View tasks\n");
    printf("3. Remove a task\n");
    printf("4. Modify Order\n");
    printf("5. Exit\n");
    scanf("%d",&user_input);
    getchar(); 
    return(user_input);

}

int main() {
    node *head = NULL;//from the beginning the head pointer is pointed to NULL
    int index = 1;
    int index_for_modifications = 1;
    char task[20];

    printf("Welcome to the to-do list app\n");
    printf("Start by adding your first task \nWhat would you like your first task to be?:\n");
    fgets(task,19,stdin);
    make_head(&head,task);
    
    int input =prompt_user();
    while (input!= 5){
        switch (input){
            case (1):
            printf("Enter the new task: ");
            fgets(task,20, stdin);
            printf("\n");
            linked_list_add(&head, task, index);
            index = index + 1;
                 
            break;

            case (2):
            print_linked_list(head);
            printf("\n");
            break;

            case (3):
            printf("Enter the position of the task to remove: ");
            scanf("%d", &index);
            printf("\n");
            linked_list_remove(&head, (index-1));
            break;

            case(4):
            print_linked_list(head);
            printf("Select the point you would like to change: ");
            scanf("%d", &index);
            printf("\n");
            printf("Select where you would like to insert your task: ");
            scanf("%d", &index_for_modifications);
            linked_list_modify(&head, (index-1), (index_for_modifications-1));
            print_linked_list(head);
            
            break;

            default:
            printf("Invalid choice. Please try again.\n");
            printf("\n");
            break;

        }

        input =prompt_user();
    }

printf("Closing the app...");
return(0);




}
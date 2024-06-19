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
    printf("4. Exit\n");
    scanf("%d",&user_input);
    getchar(); 
    return(user_input);

}

int main() {
    node *head = NULL;
    int index;
    char task[20];

    printf("Welcome to the to-do list app\n");
    printf("Start by adding your first task \n What would you like your first task to be?:\n");
    fgets(task,19,stdin);
    make_head(&head,task);
    
    int input =prompt_user();
    while (input!= 4){
        switch (input){
            case (1):
            printf("Enter the new task: ");
            fgets(task,20, stdin);
            printf("\n");
            printf("Enter the position to insert the task: ");
            scanf("%d", &index);
            
            linked_list_add(&head, task, index);
                 
            break;

            case (2):
            print_linked_list(head);
            printf("\n");
            break;

            case (3):
            printf("Enter the position of the task to remove: ");
            scanf("%d", &index);
            printf("\n");
            linked_list_remove(&head, index);
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
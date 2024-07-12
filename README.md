![GitHub last commit (branch)](https://img.shields.io/github/last-commit/ksingh66/todo-aoi-list/main)
![To-do_List✍🏽](https://github.com/user-attachments/assets/1eaecbca-21fd-44b8-9ed0-b17b9fa6ff82)
# How to use
Type "make" in the terminal to compile the program. Then type "./todo_list" to run the program.
Note that the tasks are stored in RAM and **terminating the program will get rid of the tasks**.
![How to use](https://github.com/user-attachments/assets/ec667ce9-94c3-4870-8674-6542f3f569b1)



# Outline
Dynamically allocate space for each task.
A Linked list will be used as the data structure that represents each task. The pointer part of the node will point to the next task to be completed with the last task pointing to NULL.

## Linked list 
 We need to write a header file for the Linked list data structure, this header file must include functions to print the list, replace two existing tasks, add a new task and remove a task. 
 ADDING A TASK
 ![linked list add](https://github.com/user-attachments/assets/327c6169-9a0f-4a4d-89e1-9250afe754be)
# Result
The final program acts as a complete linked list, that is able to show tasks, add and remove tasks as well as swap two tasks.
![result](https://github.com/user-attachments/assets/47ea4e5c-c050-4941-873a-027a2ef67b02)
# Thank you for your time# Plan for the project
The idea is to *dynamically allocate memory* for each of the tasks in the to-do list.

**To compile the program type "make" in the commandline**

We will have 3 files **linked_list.h**,**linked_list.c** and lastly **main.c**
## Linked-list
Linked-lists will be used to keep track of the order of the tasks.

We will use the header of the data structure linked-list to use in our main file.
The main purpose of the project is to get familiar with the Linked-list data structure.
Update Jun 18: linked list data stucture initialized

To update soon: Finish all functions for the linked list ADT

To update in future: Dynamically allocate space

## Main
Key: user can change the priority order- additionally when a user a done with a task we want the program to output the order of the new priority tasks.

The UI prompts the user to either add a task, mark a task as done or change the priority order. 

BONUS: having multiple users would be good too.

BONUT: Encrypting the content of the files would also be good too.

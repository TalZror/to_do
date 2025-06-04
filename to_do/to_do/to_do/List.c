#include "List.h"
#include "Task.h"
#include <stdlib.h>
#include <stdio.h>

// Frees a single list node and its associated task
static void list_free_list(list_ptr node) {
    free(node->Task);
    free(node);
}

// Frees the entire linked list
void List_clear_list(list_ptr head) {
    list_ptr current = head;
    while (current != NULL) {
        list_ptr next = current->next;
        list_free_list(current);
        current = next;
    }
}

// Adds a new task to the end of the list
void List_Add_Task(list_ptr* head, Task_ptr task) {
    list_ptr new_node = (list_ptr)malloc(sizeof(list));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed for new list node.\n");
        exit(EXIT_FAILURE);
    }
    new_node->Task = task;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        list_ptr current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Displays all tasks in the list with their details
void List_show_tasks(list_ptr head) {
    printf("\033[0;34m======================Task Details:======================\033[0m\n");
    if (head == NULL) {
        printf("No tasks available.\n");
        return;
    }
    list_ptr current = head;
    size_t count = 0;
    while (current != NULL) {
        count++;
        printf("\nTask %zu:\n", count);
        Task_print_Task(current->Task);
        current = current->next;
    }
}

// Removes a task at the specified position from the list
void List_remove_task(list_ptr* head, int task_number) {
    if (task_number < 1) {
        printf("Invalid task number.\n");
        return;
    }
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    list_ptr current = *head;
    if (task_number == 1) {
        *head = current->next;
        list_free_list(current);
        printf("Task %d removed successfully.\n", task_number);
    }
    else {
        list_ptr previous = NULL;
        int count = 1;
        while (current != NULL && count < task_number) {
            previous = current;
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Task %d does not exist.\n", task_number);
            return;
        }
        previous->next = current->next;
        list_free_list(current);
        printf("Task %d removed successfully.\n", task_number);
    }
}

// Updates the progress status of a specific task in the list
void List_update_task_progress(list_ptr head, int task_number, int progress) {
    if (task_number < 1) {
        printf("Invalid task number.\n");
        return;
    }

    if (progress < NOT_STARTED || progress > COMPLETED) {
        printf("Invalid progress value. Use 0 = Not Started, 1 = In Progress, 2 = Completed.\n");
        return;
    }

    int count = 1;
    while (head != NULL && count < task_number) {
        head = head->next;
        count++;
    }

    if (head == NULL) {
        printf("Task %d does not exist.\n", task_number);
        return;
    }

    head->Task->task_progress = progress;
    printf("Task %d progress updated!\n", task_number);
}

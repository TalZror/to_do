#pragma once
#include "Task.h"

typedef struct list {
    Task_ptr Task;
    struct list* next;
} list, * list_ptr;

void List_clear_list(list_ptr head);
void List_Add_Task(list_ptr* head, Task_ptr task);
void List_show_tasks(list_ptr head);
void List_remove_task(list_ptr* head, int task_number);
void List_update_task_progress(list_ptr head, int task_number, int progress);

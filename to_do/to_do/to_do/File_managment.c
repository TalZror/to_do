#include "File_managment.h"
#include <stdio.h>

// Saves the current list of tasks to a binary file
void File_managment_save_to_file(list_ptr head) {
    FILE* file = fopen(FILENAME, "wb");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return;
    }

    if (head == NULL) {
        // Empty list — clear file
        fclose(file);
        printf("No tasks to save. File cleared.\n");
        return;
    }

    list_ptr current = head;
    while (current != NULL) {
        Task_ptr task = current->Task;

        if (task == NULL) {
            printf("Skipping NULL task pointer\n");
            current = current->next;
            continue;
        }

        printf("Saving task: %s, %s, %s, %d, %d\n",
            task->task_name,
            task->task_desc,
            task->task_Date,
            task->task_priority,
            task->task_progress);

        size_t written = fwrite(task, sizeof(Task), 1, file);
        if (written != 1) {
            printf("Error writing task to file\n");
        }

        current = current->next;
    }

    printf("Saved to file\n");
    fclose(file);
}

// Loads tasks from the binary file into the linked list
void File_managment_load_from_file(list_ptr* head) {
    List_clear_list(*head);
    *head = NULL;

    FILE* file = fopen(FILENAME, "rb");
    if (file == NULL) {
        perror("Failed to open file for reading");
        return;
    }

    Task task;
    while (fread(&task, sizeof(Task), 1, file) == 1) {
        Task_ptr tmp = Task_create(
            task.task_name,
            task.task_desc,
            task.task_Date,
            task.task_priority,
            task.task_progress
        );
        List_Add_Task(head, tmp);
    }

    printf("Loaded tasks from file\n");
    fclose(file);
}

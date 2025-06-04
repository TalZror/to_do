#include "Utils.h"

// Displays the progress of a task in colored text
static void Utils_show_progress(int progress) {
    if (progress == NOT_STARTED) {
        printf("\033[0;37mProgress:\033[0m Not Started\n");
    }
    else if (progress == IN_PROGRESS) {
        printf("\033[0;33mProgress:\033[0m In Progress\n");
    }
    else if (progress == COMPLETED) {
        printf("\033[0;32mProgress:\033[0m Completed\n");
    }
}

// Displays the priority level of a task in colored text
static void Utils_show_priority(int priority) {
    if (priority == LOW) {
        printf("\033[0;37mPriority:\033[0m Low\n");
    }
    else if (priority == MEDIUM) {
        printf("\033[0;33mPriority:\033[0m Medium\n");
    }
    else if (priority == HIGH) {
        printf("\033[0;32mPriority:\033[0m High\n");
    }
}

// Prints task details using color based on priority and progress
void Utils_draw_based_priority(Task_ptr task) {
    if (task->task_priority == LOW) {
        printf("\033[0;32mTask Name:\033[0m %s\n", task->task_name);
        printf("\033[0;32mDescription:\033[0m %s\n", task->task_desc);
        printf("\033[0;32mDate:\033[0m %s\n", task->task_Date);
    }
    else if (task->task_priority == MEDIUM) {
        printf("\033[0;33mTask Name:\033[0m %s\n", task->task_name);
        printf("\033[0;33mDescription:\033[0m %s\n", task->task_desc);
        printf("\033[0;33mDate:\033[0m %s\n", task->task_Date);
    }
    else if (task->task_priority == HIGH) {
        printf("\033[0;31mTask Name:\033[0m %s\n", task->task_name);
        printf("\033[0;31mDescription:\033[0m %s\n", task->task_desc);
        printf("\033[0;31mDate:\033[0m %s\n", task->task_Date);
    }

    Utils_show_priority(task->task_priority);
    Utils_show_progress(task->task_progress);
}

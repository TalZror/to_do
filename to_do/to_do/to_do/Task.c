#include "Task.h"
#include <ctype.h>
#include <string.h>

// Checks if a given date string is valid and formatted as YYYY-MM-DD
int is_valid_date(const char* date_str) {
    if (strlen(date_str) != 10)
        return 0;

    if (date_str[4] != '-' || date_str[7] != '-')
        return 0;

    int year, month, day;
    if (sscanf_s(date_str, "%4d-%2d-%2d", &year, &month, &day) != 3)
        return 0;

    if (year < 2025) return 0;
    if (month < 1 || month > 12) return 0;

    int max_day = 31;
    switch (month) {
    case 4: case 6: case 9: case 11:
        max_day = 30;
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            max_day = 29;
        else
            max_day = 28;
        break;
    }

    if (day < 1 || day > max_day)
        return 0;

    return 1;
}

// Creates a new task from user input
Task_ptr Task_add_Task() {
    char task_name[TEXT_LENGTH];
    char task_desc[TEXT_LENGTH];
    char date[DATE_LENGTH];
    int priority;

    printf("Enter task name : ");
    scanf_s(" %s", task_name, (unsigned)_countof(task_name));

    printf("Enter task desc : ");
    scanf_s(" %s", task_desc, (unsigned)_countof(task_desc));

    while (1) {
        printf("Enter task date (YYYY-MM-DD): ");
        scanf_s(" %s", date, (unsigned)_countof(date));
        if (!is_valid_date(date)) {
            printf("Invalid date. Please enter a valid future date in format YYYY-MM-DD.\n");
            continue;
        }
        break;
    }

    while (1) {
        printf("Enter task priority (0 = LOW, 1 = MEDIUM, 2 = HIGH): ");
        if (scanf_s("%d", &priority) != 1) {
            printf("Invalid input. Please enter a number between 0 and 2.\n");
            while (getchar() != '\n');
            continue;
        }
        if (priority < LOW || priority > HIGH) {
            printf("Priority out of range. Please enter 0, 1, or 2.\n");
            continue;
        }
        break;
    }

    Task_ptr new_task = (Task_ptr)malloc(sizeof(Task));
    if (new_task == NULL) {
        fprintf(stderr, "Memory allocation failed for new task.\n");
        exit(EXIT_FAILURE);
    }

    strcpy_s(new_task->task_name, TEXT_LENGTH, task_name);
    strcpy_s(new_task->task_desc, TEXT_LENGTH, task_desc);
    strcpy_s(new_task->task_Date, DATE_LENGTH, date);
    new_task->task_priority = priority;
    new_task->task_progress = NOT_STARTED;

    return new_task;
}

// Prints task using colored formatting
void Task_print_Task(Task_ptr task) {
    Utils_draw_based_priority(task);
}

// Creates a task from given parameters
Task_ptr Task_create(const char* name, const char* description, const char* date, int priority, int progress) {
    Task_ptr new_task = (Task_ptr)malloc(sizeof(Task));
    if (new_task == NULL) {
        fprintf(stderr, "Memory allocation failed for new task.\n");
        exit(EXIT_FAILURE);
    }

    strcpy_s(new_task->task_name, TEXT_LENGTH, name);
    strcpy_s(new_task->task_desc, TEXT_LENGTH, description);
    strcpy_s(new_task->task_Date, DATE_LENGTH, date);
    new_task->task_priority = priority;
    new_task->task_progress = progress;

    return new_task;
}

#include "Task.h"

#define TEXT_LENGTH 256
#define DATE_LENGTH 11

Task_ptr Task_add_Task() {
	char* task_name = NULL;
	char* task_desc = NULL;

	char* date = NULL;
	int priority;

	printf("Enter task name : ");
	task_name = (char*)malloc(TEXT_LENGTH * sizeof(char));
	if (task_name == NULL) {
		fprintf(stderr, "Memory allocation failed for task name.\n");
		exit(EXIT_FAILURE);
	}
	scanf_s(" %s", task_name, TEXT_LENGTH);
	printf("%s\n", task_name);


	printf("Enter task desc : ");
	task_desc = (char*)malloc(TEXT_LENGTH * sizeof(char));
	if (task_desc == NULL) {
		fprintf(stderr, "Memory allocation failed for task desc.\n");
		free(task_name);
		exit(EXIT_FAILURE);
	}
	scanf_s(" %s", task_desc, TEXT_LENGTH);

	printf("Enter task date (YYYY-MM-DD): ");
	date = (char*)malloc(DATE_LENGTH* sizeof(char));
	if (date == NULL) {
		fprintf(stderr, "Memory allocation failed for task date.\n");
		free(task_desc);
		free(task_name);
		exit(EXIT_FAILURE);
	}
	scanf_s(" %s", date, DATE_LENGTH);



	printf("Enter task priority (0 for LOW, 1 for MEDIUM, 2 for HIGH): ");
	scanf_s("%d", &priority);

	if (priority < LOW || priority > HIGH) {
		fprintf(stderr, "Invalid priority. Please enter 0, 1, or 2.\n");
		free(task_desc);
		free(task_name);
		free(date);
		exit(EXIT_FAILURE);
	}

	Task_ptr new_task = (Task_ptr)malloc(sizeof( Task));
	if (new_task == NULL) {
		fprintf(stderr, "Memory allocation failed for new task.\n");
		free(task_desc);
		free(task_name);
		free(date);
		exit(EXIT_FAILURE);
	}

	new_task->task_name = task_name;
	new_task->task_desc = task_desc;
	new_task->Date = date;
	new_task->priority = priority;
	return new_task;
}


void Task_print_Task(Task_ptr task) {

	Utils_draw_based_priority(task);
}
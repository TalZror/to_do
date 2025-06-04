#pragma once

#include <stdio.h>
#include "Utils.h"
#include <stdlib.h>

#define TEXT_LENGTH 256
#define DATE_LENGTH 11

typedef struct {
	char task_name[TEXT_LENGTH];
	char task_desc[TEXT_LENGTH];
	char task_Date[DATE_LENGTH];
	int task_priority;
	int task_progress;
} Task,*Task_ptr;

Task_ptr Task_add_Task(void);

void Task_print_Task(Task_ptr );
Task_ptr Task_create(const char* name, const char* description, const char* date, int priority, int progress);

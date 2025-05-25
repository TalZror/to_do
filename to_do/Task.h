#pragma once

#include <stdio.h>
#include "Utils.h"
#include <stdlib.h>


typedef struct {
	char *task_name;
	char* task_desc;
	char * Date;
	int priority;
} Task,*Task_ptr;

Task_ptr Task_add_Task(void);

void Task_print_Task(Task_ptr );

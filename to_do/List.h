#pragma once
#include "Task.h"
typedef struct  list {
	Task_ptr Task;
	struct list* next;

} list, *list_ptr;

#pragma once
#include "stdlib.h"
#include "Task.h"


 enum Priority {
	LOW,
	MEDIUM,
	HIGH
};
 enum Progress {
	 NOT_STARTED,
	 IN_PROGRESS,
	 COMPLETED
 };


 enum boolean {
	 False,
	 True
 };


 void Utils_draw_based_priority(Task_ptr);


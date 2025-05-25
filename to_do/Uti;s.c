#include "Utils.h"



void Utils_draw_based_priority(Task_ptr task) {
	system("cls");
	printf("\033[0;34m======================Task Details:======================\033[0m\n");
	
	
	if (task->priority == LOW) {
		printf("\033[0;32mTask Name:\033[0m %s\n", task->task_name);
		printf("\033[0;32mDescription:\033[0m %s\n", task->task_desc);
		printf("\033[0;32mDate:\033[0m %s\n", task->Date);
		printf("\033[0;32mPriority:\033[0m %d\n",task->priority);
	}
	else if (task->priority == MEDIUM) {
		printf("\033[0;33mTask Name:\033[0m %s\n", task->task_name);
		printf("\033[0;33mDescription:\033[0m %s\n", task->task_desc);
		printf("\033[0;33mDate:\033[0m %s\n", task->Date);
		printf("\033[0;33mPriority:\033[0m %d\n", task->priority);
	}
	else if (task->priority == HIGH) {
		printf("\033[0;31mTask Name:\033[0m %s\n", task->task_name);
		printf("\033[0;31mDescription:\033[0m %s\n", task->task_desc);
		printf("\033[0;31mDate:\033[0m %s\n", task->Date);
		printf("\033[0;31mPriority:\033[0m %d\n", task->priority);

	}
	else  {
		
	}
	

}
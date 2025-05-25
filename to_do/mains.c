#include "Task.h"
#include "List.h"
#include "Utils.h"
#define FILENAME "animals.txt"
#define HELLO_STRING " enter option\n1)add Task"


list_ptr head = NULL;


int main() {
    int choice;

    do {
        system("cls");
        puts(HELLO_STRING);
        scanf_s("%d", &choice);


        switch (choice) {
        case 1: 
        { 
            Task_ptr task_ptr = Task_add_Task();
			Task_print_Task(task_ptr);
            break;
        }
        default:  printf("wrong option");break;
        }



    } while (False);


    return 0;
}

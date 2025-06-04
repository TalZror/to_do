#include "Task.h"
#include "List.h"
#include "Utils.h"
#include "File_managment.h"

#define HELLO_STRING "enter option\n1)clear screen\n2)add Task\n3)show tasks\n4)remove task\n5)Save to file\n6)Load from file\n7)Update task progress\n8)exit"

list_ptr head = NULL;

// Main menu loop
int main() {
    int choice;
    char flag = False;
    do {
        puts(HELLO_STRING);
        if (scanf_s("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 8.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            system("cls");
            break;
        }
        case 2: {
            Task_ptr task_ptr = Task_add_Task();
            List_Add_Task(&head, task_ptr);
            break;
        }
        case 3: {
            List_show_tasks(head);
            break;
        }
        case 4: {
            printf("Enter task to remove:\n");
            int task_number;
            if (scanf_s("%d", &task_number) != 1) {
                printf("Invalid input. Please enter a valid task number.\n");
                while (getchar() != '\n');
                break;
            }
            List_remove_task(&head, task_number);
            File_managment_save_to_file(head);
            break;
        }
        case 5: {
            File_managment_save_to_file(head);
            break;
        }
        case 6: {
            File_managment_load_from_file(&head);
            break;
        }
        case 7: {
            int task_number, progress;
            printf("Enter task number to update progress:\n");
            if (scanf_s("%d", &task_number) != 1) {
                printf("Invalid input. Please enter a valid task number.\n");
                while (getchar() != '\n');
                break;
            }
            printf("Enter new progress: 0 = Not Started, 1 = In Progress, 2 = Completed\n");
            if (scanf_s("%d", &progress) != 1) {
                printf("Invalid input. Please enter a number between 0 and 2.\n");
                while (getchar() != '\n');
                break;
            }
            List_update_task_progress(head, task_number, progress);
            break;
        }
        case 8: {
            printf("Exiting the program...\n");
            flag = True;
            break;
        }
        default:
            printf("Please enter a number between 1–8\n");
            break;
        }
    } while (flag == False);

    return 0;
}

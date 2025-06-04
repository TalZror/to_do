#pragma once

#include <stdio.h>
#include "Task.h"
#include "List.h"

#define FILENAME "task101.txt"

void File_managment_save_to_file(list_ptr head);
void File_managment_load_from_file(list_ptr* head);

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef int bool;
#define true 1
#define false 0

int env_var();
int env_var_to_file(char* argv_1, char * argv_2);
bool check_env_var();
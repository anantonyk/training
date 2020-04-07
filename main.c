#include <stdio.h>
#include "env_var.h"

int main(int argc, char* argv[]) {
    if(!check_env_var())
        return 123;

    if (argc == 1) {
        printf("%s\n", argv[0]);
        return env_var();
    }

    if (argc == 3){
        printf("%s %s %s\n", argv[0], argv[1], argv[2]);
        return env_var_to_file(argv[1], argv[2]);
    }
    return 0;
}
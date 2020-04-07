#include "env_var.h"

extern int errno;

const char* my_var;

bool check_env_var(){
    my_var = getenv("MY_VAR");
    if (my_var == NULL) {
        fprintf(stderr,"MY_VAR is not set\n");
        return false;
    }
    return true;
}

int env_var_to_file(char* argv_1, char * argv_2){
    int errnum;
    FILE *file_for_write = fopen(argv_2, "w");
    
    if (file_for_write == NULL) {
        errnum = errno;
        printf("Error opening file: %s\n", strerror(errnum));
        return 1;
    }

    if (strncmp("-o", argv_1, 2)) {
        return 1;
    }

    fprintf(file_for_write, "%s\n", my_var);

    if (ferror(file_for_write)) {
        errnum = errno;
        printf("Error in file: %s\n", strerror(errnum));
        return 1;
    }
    return 0;
}

int env_var(){
    printf("%s\n", my_var);
    return 0;
}
#ifndef BL0B_H
#define BL0B_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef struct {
    char* name;
    char* data;
} Blob;

int is_directory (char *path);
int is_file (char *path);


#endif
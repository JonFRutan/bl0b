#ifndef BL0B_H
#define BL0B_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>

typedef struct {
    char* file_name;
    size_t file_size;
    char* data;
} Blob;

int is_directory (char *path);
int is_file (char *path);
Blob *blob_main(char *path);
Blob *blob_directory(char *path);
Blob *blob_file(char *file);
void free_blob(Blob *blob);
void print_hex(const char *data, size_t size);

#endif
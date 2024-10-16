//jfr
//bl0b is for creating blobs of data.
#include "bl0b.h"

int main (int argc, char *argv[]) {
    if (argc <= 1) {
        printf("No arguments provided.");
        return 0;
    }

    if (!is_directory(argv[1]) && !is_file(argv[1])) {
        printf("Not a valid file / path.");
        return 0;
    }
    Blob *blob = blob_main(argv[1]);
    printf("File Name: %s\nFile Size: %d\n",blob->file_name, blob->file_size);
    print_hex(blob->data, blob->file_size);
    free_blob(blob);
}

Blob *blob_main(char *path) {
    if (is_directory(path)) {
        return blob_directory(path);
    }
    else if (is_file) {
        return blob_file(path);
    }
}

Blob *blob_directory(char *path) {
    return NULL;
}


//Takes in the file path and creates a blob of the file.
//NOTE - MAKE SURE ANYTHING CALLING blob_file IS PROVIDING A FILE PATH!
Blob *blob_file(char *path) {
    FILE *file = fopen(path, "rb");                                //File opened - Resolved before return.
    if (!file) {
        perror("File couldn't be opened.");
        return NULL;
    }
    fseek(file, 0, SEEK_END);         //Move to the end of the file.
    size_t file_read_size = ftell(file);   //ftell returns current position (end of file).
    fseek(file, 0, SEEK_SET);         //Move pointer back to beginning.

    Blob *file_blob = (Blob *)malloc(sizeof(Blob));               //malloc call 1 - free_blob resolves
    //FIXME - Add error handling here in case of malloc failure.
    file_blob->file_name = strdup(path);                          //FIXME - Delimit name based on '\'
    file_blob->data = (char *)malloc(file_read_size);             //malloc call 2 - free_blob resolves
    file_blob->file_size = file_read_size;

    //Reading in data...
    fread(file_blob->data, 1, file_read_size, file);
    fclose(file);
    return file_blob;
}

void free_blob(Blob *blob) {
    if (blob) {
        if (blob->data) {
            free(blob->data);
        }
        if (blob->file_name) {
            free(blob->file_name);
        }
        free(blob);       
    }
}


//Checks whether the path is a directory, returns 0 if it isn't.
int is_directory (char *path) {
    struct stat path_stat;             //path_stat is a structure containing info about a directory
    stat(path, &path_stat);            //stat() retrieves information on the file/directory
    return S_ISDIR(path_stat.st_mode); //S_ISDIR is a macro from sys/stat.h that determines if the path is to a directory.
}

//Checks whether the path is a file, returns 0 if it's not.
int is_file (char *path) {
    struct stat path_stat;             //Creates stat object
    stat(path, &path_stat);            //Fills in stat object
    return S_ISREG(path_stat.st_mode); //Macro- Is it a file?
}

//Provided by ChatGPT - Iterates through the data and prints it out in hex for file comparison.
void print_hex(const char *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%02X ", (unsigned char)data[i]);  // Print each byte in hex
    }
    printf("\n");
}
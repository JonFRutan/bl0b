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
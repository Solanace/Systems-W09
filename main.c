#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int size = 0;
    char dir[] = "../Systems-W06";
    DIR *dirp = opendir(dir);
    struct dirent *current_file = readdir(dirp);
    printf("Info for directory: %s\n", dir);
    
    printf("Directories:\n");
    while (current_file) {
        struct stat sb;
        stat(current_file->d_name, &sb);
        size += sb.st_size;
        if (!current_file->d_type) printf("    %s\n", current_file->d_name);
        //if (current_file->d_type) printf("    %s\n", current_file->d_name);
        //else printf("    Directory: %s\n", current_file->d_name);
        current_file = readdir(dirp);
    }
    
    dirp = opendir(dir);
    current_file = readdir(dirp);
    
    printf("Regular files:\n");
    while (current_file) {
        if (current_file->d_type) printf("    %s\n", current_file->d_name);
        current_file = readdir(dirp);
    }
    
    printf("Total directory size: %d bytes\n", size);
    closedir(dirp);
    return 0;
}

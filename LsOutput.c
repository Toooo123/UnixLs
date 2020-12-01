#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

#include "LsOutput.h"

void printNewLine() {
    printf("\n");
}

void printDirectory(char * directory) {
    printf("%s:\n", directory);
}

void printFilename(char * filename) {
    printf("%s\n", filename);
}

void printInode(long inode) {
    printf("%ld ", inode);
}

void printl(struct stat buf) {
    printPermission(buf.st_mode);
    printf("%ld ", buf.st_nlink);
    printf("%d ", buf.st_uid);
    printf("%d ", buf.st_gid);
    printf("%5ld ", buf.st_size);
    printDate(buf.st_mtim);
}

void printPermission(mode_t mode) {
}

void printDate(struct timespec time) {
    time_t seconds = time.tv_sec;
    struct tm * local = localtime(&seconds);

    char * months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    printf("%s %2d ", months[local->tm_mon], local->tm_mday);

    int hour = local->tm_hour;

    if (hour < 10) {
        printf("0%d:", hour);
    } else {
        printf("%d:", hour);
    }

    int min = local->tm_min;
    if (min < 10) {
        printf("0%d ", min);
    } else {
        printf("%d ", min);
    }
}
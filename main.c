#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *buffer = NULL;
size_t buffer_sz = 0;

void usage() {
    fprintf(stderr, "cext: usage: cext extension filename1 [filename2...]\n");
}

void adjust_buffer(size_t sz) {
    if (sz > buffer_sz) {
        free(buffer);

        size_t actual_sz = 1;
        while (actual_sz < sz)
            actual_sz <<= 1;

        buffer_sz = actual_sz;
        buffer = malloc(buffer_sz);
        if (buffer == 0) {
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }
    }
}

void print_result(const char *str) {
    fprintf(stdout, "%s\n", str);
}

void replace_extension(int ix, const char *filename, const char *extension) {
    
    char *last_dot = strrchr(filename, '.');
    
    size_t filename_len;
    if (last_dot == NULL) {
        filename_len = strlen(filename);
    } else {
        filename_len = last_dot - filename;
    }

    adjust_buffer(filename_len + strlen(extension) + 2);

    memcpy(buffer, filename, filename_len);
    buffer[filename_len] = '.';
    strcpy(buffer + filename_len + 1, extension);

    print_result(buffer);

}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        usage();
        exit(1);
    }

    for (int i = 2; i < argc; ++i) {
        replace_extension(i - 2, argv[i], argv[1]);
    }

}
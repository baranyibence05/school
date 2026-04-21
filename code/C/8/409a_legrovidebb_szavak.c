#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Nem adtál meg egyetlen szót sem!\n");
        return 1;
    }

    int min_length = -1;
    for (int i = 1; i < argc; i++) {
        int length = 0;
        while (argv[i][length] != '\0') length++;
        if (min_length == -1 || length < min_length) min_length = length;
    }

    for (int i = 1; i < argc; i++) {
        int length = 0;
        while (argv[i][length] != '\0') length++;
        if (length == min_length) printf("%s\n", argv[i]);
    }
    
    return 0;
}
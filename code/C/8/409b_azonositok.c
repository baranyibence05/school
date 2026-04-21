#include <stdio.h>
#include <string.h>
#include "prog1.h"

int is_valid_c_identifier(const char* input) {
    if (input[0] == '\0') return 0; 
    if (!((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z') || input[0] == '_')) {
        return 0; 
    }
    for (int i = 1; input[i] != '\0'; i++) {
        if (!((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9') || input[i] == '_')) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    char input[100];
    printf("Adj meg sztringeket '*' végjelig!\n");
    while (1) {
        printf("Input: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (input[0] == '*' && input[1] == '\0') break; 
        printf("%s\n", is_valid_c_identifier(input) ? "YES" : "NO");
    }
    return 0;
}
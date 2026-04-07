#include "prog1.h"
#include <stdio.h>
#include <string.h>

int is_strong_password(const string password) {
    int has_lower = 0;
    int has_upper = 0;
    int has_digit = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') has_lower = 1;
        else if (password[i] >= 'A' && password[i] <= 'Z') has_upper = 1;
        else if (password[i] >= '0' && password[i] <= '9') has_digit = 1;
    }

    return strlen(password) >= 8 && has_lower && has_upper && has_digit;
}
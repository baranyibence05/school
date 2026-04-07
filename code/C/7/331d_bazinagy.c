#include <stdio.h>
#include <string.h>

int main() {
    string number = get_string("Szám: ");
    int sum = 0;
    for (int i = 0; number[i] != '\0'; i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            sum += number[i] - '0';
        }
    }
    printf("A számjegyek összege: %d\n", sum);
    return 0;
}
#include <stdio.h>
#include "prog1.h"

int rfind_char(string s, char c) {
    int last_index = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) last_index = i;
    }
    return last_index;
}
int main() {
    string s = "hatalmas cicak ugranak a cinegek utan";
    char ch = 'c';
    
    int index = rfind_char(s, ch);
    
    if (index != -1) {
        printf("Az utolsó '%c' karakter indexe: %d\n", ch, index);
    } else {
        printf("A karakter '%c' nem található a sztringben.\n", ch);
    }
    
    return 0;
}
#include <stdio.h>
#include "prog1.h"

int char_count(string s, char c) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            count++;
        }
    }
    
    return count;
}

int main() {
    char szoveg[] = "cica";
    char keresett = 'c';
    
    int eredmeny = char_count(szoveg, keresett);
    
    printf("A vizsgalt sztring: \"%s\"\n", szoveg);
    printf("A keresett karakter: '%c'\n", keresett);
    printf("Elofordulasok szama: %d\n", eredmeny);

    return 0;
}
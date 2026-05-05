#include <stdio.h>
#include <ctype.h>

int strcmpi(const char* s1, const char* s2) {
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;
    unsigned char karakter_1, karakter_2;

    do {
        karakter_1 = tolower(*p1++);
        karakter_2 = tolower(*p2++);

        if (karakter_1 == '\0') {
            break;
        }
    } while (karakter_1 == karakter_2);

    return karakter_1 - karakter_2;
}

int main() {
    char szo_egy[] = "ez";
    char szo_ketto[] = "EZ";
    char szo_harom[] = "alma";
    char szo_negy[] = "ALMA";
    
    printf("'%s' es '%s' osszehasonlitasa: %d\n", szo_egy, szo_ketto, strcmpi(szo_egy, szo_ketto));
    printf("'%s' es '%s' osszehasonlitasa: %d\n", szo_egy, szo_harom, strcmpi(szo_egy, szo_harom));
    printf("'%s' es '%s' osszehasonlitasa: %d\n", szo_harom, szo_negy, strcmpi(szo_harom, szo_negy));

    return 0;
}
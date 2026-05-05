#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void my_strfry(char *sztring) 
{
    if (sztring == NULL) {
        return;
    }

    int hossz = strlen(sztring);
    if (hossz < 2) {
        return; 
    }

    for (int i = hossz - 1; i > 0; i--) 
    {
        int j = rand() % (i + 1);

        char ideiglenes = sztring[i];
        sztring[i] = sztring[j];
        sztring[j] = ideiglenes;
    }
}

int main() 
{
    srand((unsigned int)time(NULL));

    char teszt_szoveg[] = "Alcatraz szokes szimulacio";

    printf("Eredeti szoveg: %s\n", teszt_szoveg);

    my_strfry(teszt_szoveg);
    printf("Osszekevert szoveg: %s\n", teszt_szoveg);

    my_strfry(teszt_szoveg);
    printf("Ujra kevert szoveg: %s\n", teszt_szoveg);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    char kisbetuk[] = "abcdefghijklmnopqrstuvwxyz";
    char nagybetuk[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char szamok[] = "0123456789";
    char specialis[] = ".,;'";
    char osszes[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,;'";

    srand(time(NULL));

    int hossz = (rand() % 5) + 8; 
    char jelszo[13];

    jelszo[0] = kisbetuk[rand() % strlen(kisbetuk)];
    jelszo[1] = nagybetuk[rand() % strlen(nagybetuk)];
    jelszo[2] = szamok[rand() % strlen(szamok)];
    jelszo[3] = specialis[rand() % strlen(specialis)];

    for (int i = 4; i < hossz; i++) {
        jelszo[i] = osszes[rand() % strlen(osszes)];
    }
    jelszo[hossz] = '\0'; 

    for (int i = hossz - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = jelszo[i];
        jelszo[i] = jelszo[j];
        jelszo[j] = temp;
    }

    printf("%s\n", jelszo);

    return 0;
}
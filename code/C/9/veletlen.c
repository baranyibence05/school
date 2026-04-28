#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int choice(const int n, const int tomb[]) {

    int veletlen_index = rand() % n;

    return tomb[veletlen_index];
}


int main() 
{
    srand(time(NULL)); 

    int szamok[] = {98, 51, 65, 12, 34, 76, 23, 45, 67, 89};
    int meret = 10;

    int valasztott = choice(meret, szamok);
    printf("A választott szám: %d\n", valasztott);

    return 0;
}
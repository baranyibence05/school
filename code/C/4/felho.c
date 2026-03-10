#include <stdio.h>

int main() {
    int meret = 5;
    int tomb[5] = {2, 1, 0, 2, 4};
    int szam = 21024;

    int ossz = 0;

    for (int i = 1; i < meret; i++) {
        int kulonbseg = tomb[i] - tomb[i - 1];
        if (kulonbseg < 0) kulonbseg = -kulonbseg;
        ossz += kulonbseg;
    }

    printf("Szomszédos felhőkarcolók magasságkülönbségének összege: %d\n", ossz);

    return 0;
}
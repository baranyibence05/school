#include "prog1.h"
#include <stdio.h>
#include <string.h>

int match_ends(int n, string words[]) 
{
    int count = 0;
    for (int i = 0; i < n; i++) 
    {
        int len = strlen(words[i]);
        if (len >= 2 && words[i][0] == words[i][len - 1]) {
            count++;
        }
    }
    return count;
}

int main()
{
    string szavak[] = { "aba", "xyz", "aa", "x", "bbb" };
    int szavak_meret = 5;

    int result = match_ends(szavak_meret, szavak);
    printf("Eredmeny: %d\n", result);


    return 0;
}
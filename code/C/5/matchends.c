#include "prog1.h"
#include <stdio.h>
#include <string.h>

int match_ends(int n, string words[])
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        int len = strlen(words[i]);
        if (len >= 2 && words[i][0] == words[i][len - 1])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string szavak1[] = { "aba", "xyz", "aa", "x", "bbb" };
    int szavak1_meret = 5;

    int eredmeny = match_ends(szavak1_meret, szavak1);
    printf("Eredmeny: %d\n", eredmeny);

    for (int i = 0; i < szavak1_meret; ++i)
    {
        puts(szavak1[i]);
    }
    return 0;
}
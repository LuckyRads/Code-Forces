#include <stdio.h>

const char *DoesDivideWithoutRemainder(short *, short *);

int main()
{
    short peopleCount = 2;
    short weight;
    scanf("%hd", &weight);

    printf("%s\n", DoesDivideWithoutRemainder(&weight, &peopleCount));
    return 0;
}

const char *DoesDivideWithoutRemainder(short *number, short *dividend)
{
    if (*number % *dividend == 0 && *number > *dividend)
        return "YES";
    else
        return "NO";
}
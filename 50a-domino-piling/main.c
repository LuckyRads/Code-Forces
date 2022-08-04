#include <stdio.h>

int main()
{
    int m, n;
    int dominoSize = 2;

    scanf("%d %d", &m, &n);

    int gridSize = n * m;

    printf("%d\n", (int)(gridSize / dominoSize));

    return 0;
}
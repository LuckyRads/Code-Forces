#include <stdio.h>
#include <stdlib.h>

int *GetInputArray(int);
void FreeArray(int *);

int main()
{
    int nParticipantCount, kPlaceScore;

    scanf("%d %d", &nParticipantCount, &kPlaceScore);

    // sorted by desc/equal
    int *scores = GetInputArray(nParticipantCount);

    int scoreToAdvance = scores[kPlaceScore - 1];
    int advancersCount = 0;
    for (int i = 0; i < nParticipantCount; i++)
    {
        if (scores[i] >= scoreToAdvance && scores[i] > 0)
            advancersCount++;
        else
            break;
    }

    FreeArray(scores);

    printf("%d\n", advancersCount);

    return 0;
}

int *GetInputArray(int n)
{
    int *array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    return array;
}

void FreeArray(int *array)
{
    free(array);
}
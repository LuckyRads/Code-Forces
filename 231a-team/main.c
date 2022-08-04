#include <stdio.h>
#include <stdlib.h>

int **GetInputArray(int *, int *);
void PrintArray(int **, int, int);
void FreeInput(int **);

int main()
{
    int n;
    int m = 3;
    int minConjunctions = 2;

    scanf("%d", &n);
    int **pp_array = GetInputArray(&n, &m);

    int solutionCount = 0;
    for (int i = 0; i < n; i++)
    {
        int personsOpinionsMatched = 0;
        for (int j = 0; j < m; j++)
        {
            personsOpinionsMatched += pp_array[i][j];
        }
        if (personsOpinionsMatched >= minConjunctions)
            solutionCount++;
    }

    FreeInput(pp_array);

    printf("%d\n", solutionCount);

    return 0;
}

int **GetInputArray(int *n, int *m)
{
    int *p_rowValues = calloc((*n) * (*m), sizeof(int));
    int **pp_array = malloc((*n) * (*m) * sizeof(int *));
    for (int i = 0; i < *n; i++)
    {
        pp_array[i] = p_rowValues + i * (*m);
        for (int j = 0; j < *m; j++)
        {
            scanf("%d", &pp_array[i][j]);
        }
    }
    return pp_array;
}

void PrintArray(int **pp_array, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf(" %d", pp_array[i][j]);
        }
        printf("\n");
    }
}

void FreeInput(int **input)
{
    free(*input);
    free(input);
}

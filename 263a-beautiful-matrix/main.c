#include <stdio.h>
#include <stdlib.h>

int **GetInputMatrix();
void FreeMatrix(int **);

int main()
{
    int nMatrix = 5;
    int mMatrix = 5;
    int wantedX = 2;
    int wantedY = 2;

    int **matrix = GetInputMatrix(nMatrix, mMatrix);

    int currentX;
    int currentY;
    for (int i = 0; i < nMatrix; i++)
    {
        for (int j = 0; j < mMatrix; j++)
        {
            if (matrix[i][j] == 1)
            {
                currentX = i;
                currentY = j;
            }
        }
    }
    FreeMatrix(matrix);

    int maxX;
    int maxY;
    int minX;
    int minY;
    if (currentX > wantedX)
    {
        maxX = currentX;
        minX = wantedX;
    }
    else
    {
        maxX = wantedX;
        minX = currentX;
    }
    if (currentY > wantedY)
    {
        maxY = currentY;
        minY = wantedY;
    }
    else
    {
        maxY = wantedY;
        minY = currentY;
    }

    int neededMoves = (maxX - minX) + (maxY - minY);
    printf("%d\n", neededMoves);

    return 0;
}

int **GetInputMatrix(int n, int m)
{
    int *p_values = malloc(n * m * sizeof(int));
    int **pp_matrix = malloc(n * m * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        pp_matrix[i] = p_values + i * m;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &pp_matrix[i][j]);
        }
    }

    return pp_matrix;
}

void FreeMatrix(int **matrix)
{
    free(*matrix);
    free(matrix);
}
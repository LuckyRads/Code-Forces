#include <stdio.h>
#include <stdlib.h>

int *GetInputVector(int);
void FreeInputVector(int *);

int main()
{
    int x = 0;
    int nStatementCount;

    scanf("%d", &nStatementCount);

    int *inputOperations = GetInputVector(nStatementCount);

    for (int i = 0; i < nStatementCount; i++)
    {
        x += inputOperations[i];
    }
    FreeInputVector(inputOperations);

    printf("%d\n", x);

    return 0;
}

int *GetInputVector(int n)
{
    // -1 is subtraction
    // 1 is addition
    int *operations = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int inputSize = 3;
        char input[inputSize];
        scanf("%s", input);

        for (int j = 0; j < inputSize; j++)
        {
            if (input[j] == '+')
            {
                operations[i] = 1;
            }
            else if (input[j] == '-')
            {
                operations[i] = -1;
            }
        }
    }
    return operations;
}

void FreeInputVector(int *vector)
{
    free(vector);
}
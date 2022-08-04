#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100 + 1

void ReadInputLineByLine(char **, short *);
void PrepareInputCharArr(char *);
short GetRealCharArrSize(char *);

int main()
{
    short lineCount;

    scanf("%hd", &lineCount);

    char **inputLines = malloc(lineCount * MAX_INPUT_SIZE * sizeof(char));

    ReadInputLineByLine(inputLines, &lineCount);

    for (short i = 0; i < lineCount; i++)
    {
        short lineSize = GetRealCharArrSize(inputLines[i]);
        if (lineSize <= 10)
            printf("%s\n", &inputLines[i][0]);
        else
            printf("%c%hd%c\n", inputLines[i][0], lineSize - 2, inputLines[i][lineSize - 1]);
    }
    for (short i = 0; i < lineCount; i++)
    {
        // Should free the memory  allocated in read input method.
        free(inputLines[i]);
    }
    // Should free memory allocated in this main function scope.
    free(inputLines);

    return 0;
}

void ReadInputLineByLine(char **inputArray, short *lineCount)
{
    for (short i = 0; i < *lineCount; i++)
    {
        char *inputWord = malloc(MAX_INPUT_SIZE * sizeof(char));
        PrepareInputCharArr(inputWord);

        scanf("%s", inputWord);

        inputArray[i] = inputWord;
        for (short j = 0; j < MAX_INPUT_SIZE; j++)
        {
            inputArray[i][j] = inputWord[j];
        }
        // TODO: Find out if freeing memory up in the hierarchy works properly.
    }
}

void PrepareInputCharArr(char *charArr)
{
    for (short i = 0; i < MAX_INPUT_SIZE; i++)
    {
        charArr[i] = 0;
    }
}

short GetRealCharArrSize(char *charArr)
{
    short arrSize = 0;
    for (short i = 0; i < MAX_INPUT_SIZE; i++)
    {
        if (charArr[i] == '\0')
            break;
        if (charArr[i] != 0)
            arrSize++;
    }
    return arrSize;
}
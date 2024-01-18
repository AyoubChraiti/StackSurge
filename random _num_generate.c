#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generateNonDuplicatedNumbers(int *numbers, int size)
{
    for (int i = 0; i < size; i++)
    {
        numbers[i] = i + 1;
    }

    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&numbers[i], &numbers[j]);
    }
}

int main()
{
    int size = 100;
    int *numbers = (int *)malloc(size * sizeof(int));
    if (numbers == NULL)
    {
        return 1;
    }
    generateNonDuplicatedNumbers(numbers, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    free(numbers);
    return 0;
}

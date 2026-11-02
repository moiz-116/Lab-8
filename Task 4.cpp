#include <stdio.h>

int findTotal(int marks[], int size)
{
    int i, total = 0;
    for (i = 0; i < size; i++)
        total += marks[i];
    return total;
}

float findPercentage(int total, int size)
{
    return (float)total / (size * 100) * 100;
}

char findGrade(float percentage)
{
    if (percentage >= 80)
        return 'A';
    else if (percentage >= 60)
        return 'B';
    else if (percentage >= 40)
        return 'C';
    return 'F';
}

int findMax(int marks[], int size)
{
    int i, max = marks[0];
    for (i = 1; i < size; i++)
    {
        if (marks[i] > max)
            max = marks[i];
    }
    return max;
}

int findMin(int marks[], int size)
{
    int i, min = marks[0];
    for (i = 1; i < size; i++)
    {
        if (marks[i] < min)
            min = marks[i];
    }
    return min;
}

void printReport(int marks[], int size)
{
    int total = findTotal(marks, size);
    float percentage = findPercentage(total, size);
    printf("Total: %d\n", total);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", findGrade(percentage));
    printf("Highest: %d\n", findMax(marks, size));
    printf("Lowest: %d\n", findMin(marks, size));
}

int main()
{
    int marks[5], i;
    printf("Enter 5 marks: ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &marks[i]);
        while (marks[i] < 0 || marks[i] > 100)
        {
            printf("Invalid mark. Enter a value between 0 and 100: ");
            scanf("%d", &marks[i]);
        }
    }
    printReport(marks, 5);
    return 0;
}
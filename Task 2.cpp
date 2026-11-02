#include <stdio.h>

int isPrime(int n)
{
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void printPrimes(int start, int end)
{
    int i;
    printf("Primes:");
    for (i = start; i <= end; i++)
    {
        if (isPrime(i))
            printf(" %d", i);
    }
    printf("\n");
}

int countPrimes(int start, int end)
{
    int i, count = 0;
    for (i = start; i <= end; i++)
    {
        if (isPrime(i))
            count++;
    }
    return count;
}

int main()
{
    int start, end;
    printf("Enter range: ");
    scanf("%d %d", &start, &end);
    while (start >= end)
    {
        printf("Invalid range. Start must be less than end.\n");
        printf("Enter range: ");
        scanf("%d %d", &start, &end);
    }
    printPrimes(start, end);
    printf("Total primes found: %d\n", countPrimes(start, end));
    return 0;
}
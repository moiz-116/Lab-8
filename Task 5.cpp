#include <stdio.h>

long factorial(int n)
{
    int i;
    long result = 1;
    for (i = 2; i <= n; i++)
        result *= i;
    return result;
}

int reverseNumber(int n)
{
    int reversed = 0, negative = 0;
    if (n < 0)
    {
        negative = 1;
        n = -n;
    }
    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    if (negative)
        return -reversed;
    return reversed;
}

int isPalindrome(int n)
{
    if (n < 0)
        return 0;
    if (n == reverseNumber(n))
        return 1;
    return 0;
}

int sumOfDigits(int n)
{
    int sum = 0;
    if (n < 0)
        n = -n;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void printFibonacci(int terms)
{
    int i;
    long long a = 0, b = 1, next;
    printf("Fibonacci Series:");
    for (i = 1; i <= terms; i++)
    {
        printf(" %lld", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main()
{
    int choice, n;
    do
    {
        printf("\n1. Factorial\n");
        printf("2. Reverse Number\n");
        printf("3. Check Palindrome\n");
        printf("4. Sum of Digits\n");
        printf("5. Fibonacci Series\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d", &n);
            if (n < 0)
                printf("Factorial is not defined for negative numbers.\n");
            else if (n > 20)
                printf("Number too large. Enter a value up to 20.\n");
            else
                printf("Factorial of %d = %ld\n", n, factorial(n));
            break;
        case 2:
            printf("Enter number: ");
            scanf("%d", &n);
            printf("Reversed number: %d\n", reverseNumber(n));
            break;
        case 3:
            printf("Enter number: ");
            scanf("%d", &n);
            if (isPalindrome(n))
                printf("%d is a palindrome.\n", n);
            else
                printf("%d is not a palindrome.\n", n);
            break;
        case 4:
            printf("Enter number: ");
            scanf("%d", &n);
            printf("Sum of digits: %d\n", sumOfDigits(n));
            break;
        case 5:
            printf("Enter number of terms: ");
            scanf("%d", &n);
            if (n <= 0)
                printf("Number of terms must be positive.\n");
            else if (n > 90)
                printf("Too many terms. Enter a value up to 90.\n");
            else
                printFibonacci(n);
            break;
        case 6:
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
    return 0;
}
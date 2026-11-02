#include <stdio.h>

float calculateBill(int units)
{
    float bill;
    if (units <= 100)
        bill = units * 10;
    else if (units <= 200)
        bill = 100 * 10 + (units - 100) * 15;
    else
        bill = 100 * 10 + 100 * 15 + (units - 200) * 20;
    return bill + 150;
}

void printBill(int units, float bill)
{
    printf("Units Consumed: %d\n", units);
    printf("Total Bill: Rs. %.2f\n", bill);
}

int main()
{
    int i, units;
    float bill;
    for (i = 1; i <= 3; i++)
    {
        printf("Enter units: ");
        scanf("%d", &units);
        while (units < 0)
        {
            printf("Units cannot be negative. Enter units: ");
            scanf("%d", &units);
        }
        bill = calculateBill(units);
        printBill(units, bill);
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

#define DAYS 5

void readWater(int water[])
{
    for (int i = 0; i < DAYS; i++) {
        printf("Glasses of water for day %d: ", i + 1);
        scanf("%d", &water[i]);
    }
}

void printWater(const int water[])
{
    for (int i = 0; i < DAYS; i++)
        printf("Day %d: %d glasses\n", i + 1, *(water + i));
}

float calculateWater(const int water[], int *total, int *maximum)
{
    *total = 0;
    *maximum = water[0];

    for (int i = 0; i < DAYS; i++) {
        *total += water[i];
        if (water[i] > *maximum)
            *maximum = water[i];
    }

    return (float)*total / DAYS;
}

int countDays(const int water[])
{
    int count = 0;

    for (int i = 0; i < DAYS; i++)
        if (water[i] >= 6)
            count++;

    return count;
}

void updateWater(int water[], int day, int amount)
{
    if (day >= 1 && day <= DAYS)
        water[day - 1] = amount;
}

int main(void)
{
    int water[DAYS], total, maximum, day, amount;
    float average;

    readWater(water);
    printf("\nWater amounts:\n");
    printWater(water);
    average = calculateWater(water, &total, &maximum);
    printf("Total: %d, Maximum: %d, Average: %.1f, Days with at least 6: %d\n",
           total, maximum, average, countDays(water));

    printf("\nEnter a day to update (1-5): ");
    scanf("%d", &day);
    printf("Enter the new water amount: ");
    scanf("%d", &amount);
    updateWater(water, day, amount);

    if (day < 1 || day > DAYS) {
        printf("Invalid day. No update was made.\n");
        return 1;
    }

    printf("\nUpdated water amounts:\n");
    printWater(water);
    average = calculateWater(water, &total, &maximum);
    printf("Total: %d, Maximum: %d, Average: %.1f, Days with at least 6: %d\n",
           total, maximum, average, countDays(water));

    return 0;
}

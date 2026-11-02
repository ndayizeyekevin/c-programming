#include <stdio.h>

#define DAYS 5

void readWater(int water[]) {
    for (int i = 0; i < DAYS; i++) {
        printf("Enter day %d glasses: ", i + 1);
        scanf("%d", &water[i]);
    }
}

void printWater(int water[]) {
    for (int i = 0; i < DAYS; i++) {
        printf("Day %d water amount: %d glasses\n", i + 1, water[i]);
    }
}

float calculateWater(int water[], int *total, int *maximum) {
    *total = 0;
    *maximum = water[0];
    for (int i = 0; i < DAYS; i++) {
        *total += water[i];
        if (water[i] > *maximum) {
            *maximum = water[i];
        }
    }

    return (float)*total / DAYS;
}

int countDays(int water[]) {
    int counter = 0;
    for (int i = 0; i < DAYS; i++) {
        if (water[i] >= 6) {
            counter++;
        }
    }
    
    return counter;
}

void updateWater(int water[DAYS], int amount, int day) {
    if (day >= 1 && day <= DAYS) {
        water[day-1] = amount;
    }
}


int main() {
    int water[DAYS], total, maximum, days, day, amount;
    float average;
    
    // Read water amounts
    readWater(water);
    
    // Print water amounts
    printWater(water);

    // Calculate Water Information
    average = calculateWater(water, &total, &maximum);
    
    printf("The total water amounts: %d glasses\nThe maximum water amount: %d glasses\nThe average water amount: %.1f glasses\n\n", total, maximum, average);

    //  Count Days 
    days = countDays(water);

    // Update Water Amount 
    printf("Enter a day number (1-5) to be updated: ");
    scanf("%d", &day);

    // Check if day number is valid
    if (day < 1 || day > 5) {
        printf("Invalid day input. Exiting ...");
        return 1;
    }

    printf("Enter new amount for day %d: ", day);
    scanf("%d", &amount);

    updateWater(water, amount, day);

    // New Records
    printf("New records \n");
    printWater(water);

    // re-calculations
    average = calculateWater(water, &total, &maximum);

    printf("The total water amounts: %d glasses\nThe average water amount: %.1f glasses\nThe maximum water amount: %d glasses\nThe number of days with at least 6 glasses: %d days", total, average, maximum, countDays(water));


    return 0;
}
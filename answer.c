#include <stdio.h>

#define DAYS 5

// Define read water function

void readWater (int water[]) {
    for (int i = 0; i < DAYS; i++) {
        printf("Enter water amount for day %d: ", i+1);
        scanf("%d", &water[i]);
    }
}

// Print water
void printWater (int water[]) {
    for (int i = 0; i < DAYS; i++) {
        printf("Water amount for day %d: is %d \n", i+1, water[i]);
    }
}

// Calculater Water Information
float calculateWater (int water[], int *maximum, int *total) {
    *maximum = water[0];
    *total = 0;
    for (int i = 0; i < DAYS; i++) {
        *total += water[i];
        if (water[i] > *maximum) {
            *maximum = water[i];
        }
    }

    // Calculate the average
    return (float)*total/DAYS;
}

int countDays (int water[]) {
    int counter = 0;
    for (int i = 0; i < DAYS; i++) {
        if (water[i] >= 6) {
            counter++;
        }
    }

    return counter;
}

// Update day's water amount
void updateWater (int water[], int day, int amount) {
    if (day >= 1 && day <= DAYS) {
        water[day-1] = amount;
    }
}

int main() {
    int water[DAYS], maximum, total, day, amount;
    // float average;

    // Read water amounts
    readWater(water);

    // Print Water Amounts 
    printWater(water);

    // Calculate Water Information 
    printf("The total amount of water: %d\nThe maximum number of glasses per day: %d glasses\nThe average number of glasses per day: %.1f glasses\n", total, maximum, calculateWater(water, &maximum, &total));
    
    // Count Days
    printf("The number of days with at least 6 glasses: %d days\n", countDays(water));

    // Update Water Amount 
    printf("Enter a day number (1-5): ");
    scanf("%d", &day);

    // Test if day is valid
    if (day < 1 || day > DAYS) {
        printf("Invalid day input. Exiting ...");
        return 1;
    }

    printf("Enter the new water amount for day %d: ", day);
    scanf("%d", &amount);

    updateWater(water, day, amount);

    // Print new daily amounts
    printf("New daily amounts\n");
    
    printWater(water);
    // Calculate Water Information 
    printf("The total amount of water: %d\nThe maximum number of glasses per day: %d glasses\nThe average number of glasses per day: %.1f glasses\n", total, maximum, calculateWater(water, &maximum, &total));
    
    // Count Days
    printf("The number of days with at least 6 glasses: %d days\n", countDays(water));


    return 0;
}
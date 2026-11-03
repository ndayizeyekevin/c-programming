#include <stdio.h>

int calculateSum(int array[], int *length) {
    int sum = 0;

    for (int i = 0; i < *length; i++) {
        sum += *(array +i);
    }

    return sum;
}

int main() {
    int length, sum = 0;

    printf("Enter the number of elements you want to record: ");
    scanf("%d", &length);

    int array[length];
    
    for (int i = 0; i < length; i++) {
        printf("Enter element %d value: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("The sum of that array is: %d", calculateSum(array, &length));

}
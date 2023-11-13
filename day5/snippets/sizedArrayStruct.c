#include <stdio.h>
#include <stdlib.h>

struct SizedArray {
    int size;
    int *data;
};

struct SizedArray initializeSizedArray(int size) {
    struct SizedArray sizedArray;
    sizedArray.size = size;
    sizedArray.data = (int *)malloc(size * sizeof(int));
	if (sizedArray.data == NULL) {
		printf("Memory allocation failed!");
		return -1;
	}

    for (int i = 0; i < size; i++) {
        sizedArray.data[i] = 0;
    }

    return sizedArray;
}

void zeroOutArray(struct SizedArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        arr->data[i] = 0;
    }
}

double findArrayAverage(struct SizedArray *arr) {
    int sum = 0;
    for (int i = 0; i < arr->size; i++) {
        sum += arr->data[i];
    }
    return (double)sum / arr->size;
}

int main() {
    int arraySize = 5;
    struct SizedArray myArray = initializeSizedArray(arraySize);

	for (int i = 0; i < arraySize; i++) {
		myArray.data[i] = 2*i + 1;
	}

	printf("Initially: \n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray.data[i]);
    }
    printf("\n");

    double average = findArrayAverage(&myArray);
    printf("Average: %.2f\n", average);

	printf("Zeroing it out!\n");
    zeroOutArray(&myArray);

    printf("Array after zeroing: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray.data[i]);
    }
    printf("\n");

    for (int i = 0; i < arraySize; i++) {
        myArray.data[i] = i + 1;
    }

    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray.data[i]);
    }
    printf("\n");

    average = findArrayAverage(&myArray);
    printf("Average: %.2f\n", average);

    return 0;
}

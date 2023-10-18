#include <stdio.h>

void printArray(int grades[], int numElements);		

float averageArray(int grades[], int numElements);		

void sortArray(int grades[], int numElements);

float medianArray(int grades[], int numElements);

int main() {
    int grades[10] = {100, 75, 63, 89, 100, 78, 90, 55, 88, 99};
    printArray(grades, 10);
    printf("Average: %.2f\n", averageArray(grades, 10));
    printf("Let's sort them!\n");
    sortArray(grades, 10);
    printArray(grades, 10);
	printf("Median: %.2f\n", medianArray(grades, 10));
}

void printArray(int grades[], int numElements) {
	printf("Grades: [");
	for (int i = 0; i < numElements; i++) {
		printf("%d", grades[i]);
		if (numElements - 1 != i) {
			printf(", ");
		}
	}
	printf("]\n");
}

float averageArray(int grades[], int numElements) {
	int sum = 0;
	for (int i = 0; i < numElements; i++) {
		sum += grades[i];
	}
	return sum / numElements;
}

void sortArray(int grades[], int numElements) {
	for (int i = 0; i < numElements - 1; i++) {
		for (int j = 0; j < numElements - i - 1; j++) {
			if (grades[j] > grades[j + 1]) {
				int temp = grades[j];
				grades[j] = grades[j + 1];
				grades[j + 1] = temp;
			}
		}
	}
}

float medianArray(int grades[], int numElements) {
	int i = 0;
	int j = numElements - 1; //The last element is always 1 fewer than the numElements!
	while (i != j && i + 1 != j) { //Account for the 2 pointers passing each other in the middle)
		i++;
		j--;
	}
	if (i == j) {
		return grades[i];
	} else {
		return (float) (grades[i] + grades[j]) / 2;
	}
}
		


#include <stdio.h>
#include <string.h>

struct Student {
    char *name;
    int grade;
};

void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
	*a = *b;
	*b = temp;
}

void sort(struct Student arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].grade > arr[j + 1].grade) {
				swap(&arr[j], &arr[j + 1]);
			} else if (arr[j].grade == arr[j + 1].grade && strcmp(arr[j].name, arr[j + 1].name) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    struct Student students[] = {
        {"Ross", 90},
        {"Gordon", 80},
        {"Cory", 80},
        {"Deborah", 100},
    };
    int n;
    int numStudents = sizeof(students) / sizeof(struct Student);
	sort(students, numStudents);

    for (n = 0; n < numStudents; n++) {
        printf("%s's grade: %d\n", students[n].name, students[n].grade);
    }
}

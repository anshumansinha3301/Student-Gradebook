#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 30

struct Student {
    char name[MAX_NAME_LENGTH];
    int id;
    float grade;
};

void displayMenu() {
    printf("\n1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numStudents < MAX_STUDENTS) {
                    printf("Enter student name: ");
                    scanf("%s", students[numStudents].name);
                    printf("Enter student ID: ");
                    scanf("%d", &students[numStudents].id);
                    printf("Enter student grade: ");
                    scanf("%f", &students[numStudents].grade);
                    numStudents++;
                } else {
                    printf("Maximum number of students reached!\n");
                }
                break;
            case 2:
                if (numStudents > 0) {
                    printf("\nStudent List:\n");
                    printf("ID\tName\tGrade\n");
                    for (int i = 0; i < numStudents; i++) {
                        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].grade);
                    }
                } else {
                    printf("No students to display. Add students first.\n");
                }
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

#include "school.h"
#define MAX_SIZE 50

void MAIN_MENU(struct Node** studentsList, int* numStudents) {
    printf("\n**====Password is Correct ^_^ ====**\n");
    printf("************************************\n");
    printf("**===         WELCOME TO       ===**\n");
    printf("**=== SCHOOL MANAGEMENT SYSTEM ===**\n");
    printf("**===       DEVELOPED BY :     ===**\n");
    printf("**===  Mohamed Ashraf Ebrahim  ===**\n");
    printf("************************************\n\n");
    printf("[1] Add a new student\n");
    printf("[2] Update information of an existing student\n");
    printf("[3] Delete a student \n");
    printf("[4] View student list \n");
    printf("[5] Count number of students \n");
    printf("[6] Rank the top 3 students\n");
    printf("[7] Exit\n");

    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            NEW_STUDENT(studentsList, numStudents);
            break;

        case 2:
            STUDENT_EDIT(*studentsList);
            break;

        case 3:
            DELETE_STUDENT(studentsList, numStudents);
            break;

        case 4:
            STUDENT_LIST(*studentsList);
            break;

        case 5:
            printf("Number of students: %d\n\n", *numStudents);
            break;

        case 6:
            RANK_STUDENT(*studentsList);
            break;


        case 7:
            printf("\n</> Exiting the program </> \n\t Goodbye!\n");
            exit(0);

        default:
            printf("\nInvalid choice. Please enter a valid option.\n");
            break;
    }
}

void NEW_STUDENT(struct Node** studentsList, int* numStudents) {

   /* Check if the maximum limit of students has been reached */
    if (*numStudents >= MAX_SIZE) {
        printf("\nCannot add more students. Maximum limit reached.\n");
        return;
    }

    /* Create a new node for the new student */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    /* Check the memory allocation success  */
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    printf("\nEnter the details for the new student:\n");

    printf("Name: ");
    fflush(stdin);
    gets(newNode->data.name);

    printf("Date of Birth in the form of (dd-mm-yyyy): ");
    fflush(stdin);
    gets(newNode->data.dateOfBirth);

    printf("ID: ");
    scanf("%d", &newNode->data.id);

    printf("Address: ");

    fflush(stdin);
    gets(newNode->data.address);

    printf("Phone Number: ");
    fflush(stdin);
    gets(newNode->data.phoneNumber);

    printf("Enter student's score in Computer Science: ");
    scanf("%f", &newNode->data.computerScienceScore);


    newNode->next = *studentsList;  /* Link the new node to the existing list */
    *studentsList = newNode;        /* To update the pointer to point the new node */

    (*numStudents)++; /* Increment the number of students */

    printf("\nNew student added successfully.\n\n\n");
}

void STUDENT_EDIT(struct Node* studentsList) {
    int idToUpdate;

     /*Ask the user for the ID of the student they want to update */
    printf("\nEnter the ID of the student you want to update: ");
    scanf("%d", &idToUpdate);

    /* Start from the beginning of the linked list */
    struct Node* current = studentsList;

    /* Check the linked list to find the student with the given ID */
    while (current != NULL) {
        if (current->data.id == idToUpdate) {
            printf("Found student with ID %d. Updating information:\n", idToUpdate);

            printf("Name: ");
            fflush(stdin);
            gets(current->data.name);

            printf("Date of Birth: ");
            fflush(stdin);
            gets(current->data.dateOfBirth);

            printf("Address: ");
            fflush(stdin);
            gets(current->data.address);

            printf("Phone Number: ");
            fflush(stdin);
            gets(current->data.phoneNumber);

            printf("Enter student's score in Computer Science: ");
            scanf("%f", &current->data.computerScienceScore);

            printf("\n *** Student information updated successfully. ***\n");
            return; /* Exit the function after updating the student's information */
        }
        current = current->next;  /* Move to the next node in the linked list */
    }
    /* If the loop finishes without finding a matching student ID */
    printf("\n Student with ID %d not found.\n\n", idToUpdate);
    printf("################################\n\n");
}

void DELETE_STUDENT(struct Node** studentsList, int* numStudents) {
/* Check if the student list is empty */
    if (*studentsList == NULL) {
        printf("No students in the list. Cannot delete.\n");
        return;
    }

    int idToDelete;
    printf("Enter the ID of the student you want to delete: ");
    scanf("%d", &idToDelete);

    /* create two poinetrs current and previous */
    struct Node* current = *studentsList;   /* Current node being examined */
    struct Node* previous = NULL; /* Previous node to keep track of the node before current */

    // Go through the linked list to find the student to delete
    while (current != NULL) {
        if (current->data.id == idToDelete) {
              //The student to delete is the first node
            if (previous == NULL) {

                /* Update the List pointer to skip the current node */
                *studentsList = current->next;
            } else {

                /* Link previous node to the node after current, effectively skipping current */
                previous->next = current->next;
            }

            free(current);    /* Free the memory of the current node */
            (*numStudents)--; /* Decrement the number of students*/
            printf("\nStudent with ID %d deleted successfully.\n", idToDelete);
            return;
        }

        /* Move to the next node */
        previous = current;
        current = current->next;
    }

    printf("\nStudent with ID %d not found. Cannot delete.\n", idToDelete);
}

void STUDENT_LIST(struct Node* studentsList) {

     /* Check if the linked list is empty */
    if (studentsList == NULL) {
        printf("No students in the list yet .\n");
        return;
    }

    printf("\n===== STUDENT LIST =====\n");

    /* Start from the beginning of the linked list */
    struct Node* current = studentsList;

    /* Go through the linked list and print each student's information */
    while (current != NULL) {
        printf("ID: %d\n", current->data.id);
        printf("Name: %s\n", current->data.name);
        printf("Date of Birth: %s\n", current->data.dateOfBirth);
        printf("Address: %s\n", current->data.address);
        printf("Phone Number: %s\n", current->data.phoneNumber);
        printf("Student Score in Computer science: %.2f\n", current->data.computerScienceScore);
        printf("\n##################\n\n");

        current = current->next; /* Move to the next node in the linked list */
    }
}

void RANK_STUDENT(struct Node* studentsList) {
    if (studentsList == NULL) {
        printf("\nNo students in the list yet.\n\n\n");
        return;
    }

    /* Create an array of pointers to store the students */
    struct Node* studentArray[MAX_SIZE]; /* Assuming a maximum of MAX_SIZE students */
    struct Node* current = studentsList;
    int count = 0;

    /* Populate the array with students from the linked list */
    while (current != NULL && count < MAX_SIZE) {
        studentArray[count] = current;
        current = current->next;
        count++;
    }

    /* Sort the array of pointers based on computer science score */
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (studentArray[j]->data.computerScienceScore < studentArray[j + 1]->data.computerScienceScore) {
                struct Node* temp = studentArray[j]; // int temp
                studentArray[j] = studentArray[j + 1];
                studentArray[j + 1] = temp;
            }
        }
    }

    /* Print the top 3 students */
    printf("\n===== TOP 3 STUDENTS =====\n");
    for (int i = 0; i < (count < 3 ? count : 3); i++) {
        printf("Rank %d:\n", i + 1);
        printf("Name: %s\n", studentArray[i]->data.name);
        printf("Computer Science Score: %.2f\n", studentArray[i]->data.computerScienceScore);
        printf("\n");
    }
}


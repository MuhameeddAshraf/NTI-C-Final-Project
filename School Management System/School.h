#ifndef SCHOOL_H_INCLUDED
#define SCHOOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*============== Structure to represent a student ================*/
struct Student {
    char name[50];
    char dateOfBirth[10];
    int id;
    char address[50];
    char phoneNumber[15];
    float computerScienceScore;
};

/*============ Create Linked list node ==============*/
struct Node {
    struct Student data; // This is where the student information is stored
    struct Node* next;   // Pointer to the next node
};

/*=============== Function prototypes ================*/
void MAIN_MENU(struct Node** studentsList, int* numStudents);
void NEW_STUDENT(struct Node** studentsList, int* numStudents);
void STUDENT_EDIT(struct Node* studentsList);
void STUDENT_LIST(struct Node* studentsList);
void DELETE_STUDENT(struct Node** studentsList, int* numStudents);
void RANK_STUDENT(struct Node* studentsList);


#endif

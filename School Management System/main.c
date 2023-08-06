/**
*****************************************************
 * @file   : main.c
 *
 * @brief  : This file contains the main functions for managing a school's student records.
 *           The program allows administrators to perform various tasks related to student management,
 *           including adding, updating, deleting, listing all students, and rank the top 3 students.
 *
 * @author : Mohamed Ashraf Ebrahim
 *
 * @date   : August 2, 2023
 ******************************************************
 **/

#include "school.h"

int main() {
    /* int flag ; */
    struct Node* studentsList = NULL;
    int numStudents = 0;
    int maxAttempts = 3;
    int attempt = 1;
    int attemptsLeft = maxAttempts;
    char pass []={"Mohamed@"};
    char userpass [20];

    while (attemptsLeft > 0) {

 for (attempt; attempt <= maxAttempts; attempt++) {
        printf("*************************************\n");
        printf("*** NTI SCHOOL MANAGEMENT SYSTEMS ***\n");
        printf("********* Attempt number %d **********\n\n", attempt);
        printf("Please enter the Admin password: ");

  scanf("%s",userpass);
  fflush(stdin);

  if (strcmp(userpass, pass)== 0){
    /*flag = 1 ; */
    MAIN_MENU(&studentsList, &numStudents);
    break;
  }
  else {
      attemptsLeft--;
      printf("\n######################################\n\n");
      printf("Invalid password \n\n");
      printf("Attempts left is %d \n\n", attemptsLeft);

  }

  if (attemptsLeft == 0) {
        printf("\nExceeded maximum attempts. Access denied.\nPlease Try Again Later \n");
    }
 }

    }

/*
if (flag == 1 ){
    MAIN_MENU(&studentsList, &numStudents);

    }
*/
    return 0;
}

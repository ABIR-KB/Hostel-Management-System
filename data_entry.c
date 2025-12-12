/**
 * @file data_entry.c
 * @brief Handles student data structure and entry functions for the Hostel Management System.
 * @details This file contains the main Student structure definition and functions for 
 * logging in, adding new students, and viewing all records.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @def FILE_NAME
 * @brief The name of the database file used to store student records.
 */
#define FILE_NAME "students.txt"

typedef struct {
    char name[100]; /**< Full name of the student. */
    char id[20];    /**< Unique Student ID number. */
    char phone[20]; /**< Contact phone number. */
    char room[20];  /**< Assigned room number. */
    char fees[20];  /**< Fee payment status (e.g., "Paid", "Pending"). */
} Student;
/**
 * @brief Authenticates the system user.
 * * Prompts the user for a username and password. 
 * @note Currently, this function does not verify the input against a database (placeholder).
 */
void secureLogin() {
    char input[20], username[20];
    printf("Enter system UserName: ");
    scanf("%s", username);
    printf("Enter system password: ");
    scanf("%s", input);

}
/**
 * @brief Adds a new student to the database.
 * * Captures student details (Name, ID, Phone, Room) from the user
 * and appends them to the "students.txt" file. 
 * Default fee status is set to "Pending".
 */

void addStudent() {
    Student s;
    FILE *fp = fopen(FILE_NAME, "a");

    printf("Enter Name: ");  scanf(" %[^\n]", s.name);
    printf("Enter ID: ");    scanf("%s", s.id);
    printf("Enter Phone: "); scanf("%s", s.phone);
    printf("Enter Room: ");  scanf("%s", s.room);

    strcpy(s.fees, "Pending");

    fprintf(fp, "%s,%s,%s,%s,%s\n",
            s.name, s.id, s.phone, s.room, s.fees);

    fclose(fp);
    printf("Student Added Successfully.\n");
}

/**
 * @brief Displays all students currently recorded in the system.
 * * Reads the "students.txt" file line by line and prints the details 
 * in a formatted table.
 */

void viewAll() {
    FILE *fp = fopen(FILE_NAME, "r");
    char line[200];

    printf("\n%-15s %-10s %-12s %-8s %-10s\n",
           "Name", "ID", "Phone", "Room", "Fees");
    printf("------------------------------------------------------\n");

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        printf("%-15s %-10s %-12s %-8s %-10s\n",
               s.name, s.id, s.phone, s.room, s.fees);
    }

    fclose(fp);
}


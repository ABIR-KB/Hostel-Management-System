/**
 * @file data_operations.c
 * @brief Handles searching, editing, and deleting student records.
 * @details This file implements the Read, Update, and Delete (CRUD) operations 
 * for the hostel management system. It uses a temporary file approach to 
 * modify the persistent "students.txt" database.
 */

#include <stdio.h>
#include <string.h>

/**
 * @brief The main database file name.
 */
#define FILE_NAME "students.txt"

/**
 * @brief Temporary file used during update and delete operations.
 */
#define TEMP "temp.txt"

/**
 * @brief Searches for a student by their unique ID.
 * * @details Prompts the user to enter an ID. The function then scans the database 
 * file line by line. If a matching ID is found, it prints the student's 
 * full details (Name, ID, Phone, Room, Fees).
 */
void searchStudent() {
    FILE *fp = fopen(FILE_NAME, "r");
    char line[200], id[20];
    int found = 0;

    printf("Enter ID to Search: ");
    scanf("%s", id);

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        if(strcmp(id, s.id) == 0) {
            printf("FOUND: %s | %s | %s | %s | %s\n",
                   s.name, s.id, s.phone, s.room, s.fees);
            found = 1;
        }
    }

    if(!found) printf("Student Not Found.\n");
    fclose(fp);
}

/**
 * @brief Modifies an existing student's record.
 * * @details This function works by:
 * 1. Opening the original file for reading and a temporary file for writing.
 * 2. Copying all data from original to temp.
 * 3. When the matching ID is found, it prompts the user for new Phone and Room data 
 * instead of copying the old data.
 * 4. Finally, it deletes the original file and renames the temp file to "students.txt".
 */
void editStudent() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen(TEMP, "w");
    char line[200], id[20];
    int found = 0;

    printf("Enter ID to Edit: ");
    scanf("%s", id);

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        if(strcmp(id, s.id) == 0) {
            printf("New Phone: "); scanf("%s", s.phone);
            printf("New Room: ");  scanf("%s", s.room);
            found = 1;
        }

        fprintf(temp, "%s,%s,%s,%s,%s\n",
                s.name, s.id, s.phone, s.room, s.fees);
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename(TEMP, FILE_NAME);

    if(found) printf("Student Updated.\n");
}

/**
 * @brief Deletes a student's record from the database.
 * * @details Similar to editStudent, this function copies data from the original
 * file to a temporary file. However, if the Student ID matches the input ID, 
 * that record is **skipped** (not written to the temp file), effectively removing it.
 */
void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen(TEMP, "w");
    char line[200], id[20];
    int found = 0;

    printf("Enter ID to Delete: ");
    scanf("%s", id);

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        if(strcmp(id, s.id) != 0)
            fprintf(temp, "%s,%s,%s,%s,%s\n",
                    s.name, s.id, s.phone, s.room, s.fees);
        else found = 1;
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename(TEMP, FILE_NAME);

    if(found) printf("Deleted Successfully.\n");
}
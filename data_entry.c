#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.txt"

typedef struct {
    char name[100];
    char id[20];
    char phone[20];
    char room[20];
    char fees[20];
} Student;

void secureLogin() {
    char input[20], username[20];
    printf("Enter system UserName: ");
    scanf("%s", username);
    printf("Enter system password: ");
    scanf("%s", input);

}


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


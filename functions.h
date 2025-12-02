#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
    char name[50];
    char id[20];
    char phone[20];
    char room[10];
    char fees[10];   // Paid / Pending
} Student;

void secureLogin();
void addStudent();
void viewAll();

void searchStudent();
void editStudent();
void deleteStudent();

void assignRoom();
void checkRoomCapacity();

void payFees();
void showDefaulters();
void changePassword();

#endif

#include "hostel.h"
#include "data_entry.c"
#include "data_operations.c"
#include "fees_security.c"
#include "room_management.c"

int main() {
    
    int auth_choice;
    int logged_in = 0;

    while (!logged_in) {
        printf("\n--- WELCOME TO HOSTEL MANAGEMENT SYSTEM ---\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("0. Exit System\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &auth_choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (auth_choice) {
            case 1:
                logged_in = userLogin(); 
                break;
            case 2:
                userRegistration();
                break;
            case 0:
                printf("Exiting System...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    int ch;
    do {
        printf("\n--- HOSTEL MANAGEMENT SYSTEM (Main Menu) ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Edit Student\n");
        printf("5. Delete Student\n");
        printf("6. Assign Room\n");
        printf("7. Check Room Capacity\n");
        printf("8. Pay Fees\n");
        printf("9. Show Defaulters\n");
        printf("10. Change Password\n");
        printf("0. Logout and Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &ch) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch(ch) {
            case 1: addStudent(); break;
            case 2: viewAll(); break;
            case 3: searchStudent(); break;
            case 4: editStudent(); break;
            case 5: deleteStudent(); break;
            case 6: assignRoom(); break;
            case 7: checkRoomCapacity(); break;
            case 8: payFees(); break;
            case 9: showDefaulters(); break;
            case 10: changePassword(); break;
            case 0: break;
            default: printf("Invalid choice. Please try again.\n");
        }

    } while(ch != 0);

    printf("Data Saved. Exiting...\n");
    return 0;
}
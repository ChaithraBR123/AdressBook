/*
Name : Chaithra B R
Date : 20/08/2024
Description: AdressBook
*/
#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. add contact\n");
        printf("2. Edit contact\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Display contacts\n");
        printf("6. Save contacts\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                editContact(&addressBook); 
                break;
            case 3:
               searchContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                listContacts(&addressBook);
                break;
            case 6:
                saveContactsToFile(&addressBook);
                break;
            case 7:
            printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                 break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
       return 0;
}

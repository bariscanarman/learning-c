#include <stdio.h>
#include <stdlib.h> // Required for dynamic memory functions like malloc() and free()
#include <string.h>

// Defining the node for our Linked List (Like a single link in a chain)
struct Contact {
    char name[50];
    char phone[20];
    struct Contact *next; // Pointer that holds the memory address of the next contact
};

// Global pointer to keep track of the start of the list (The head of the chain)
struct Contact *head = NULL;

// Function Prototypes
void add_contact();

int main() {

        int choice;

    while (1) {
        printf("\n=== Contact Management System ===\n");
        printf("1. Add a New Contact\n");
        printf("2. Exit\n");
        printf("Enter your choice");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
               add_contact();
               break;

            case 2:
               printf("Exiting...Goodbye!\n");
               return 0;

            default:
               printf("Error: Invalid choice. Please try again.\n");
    }
}

 return 0;
 
}
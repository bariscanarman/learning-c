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
void display_contacts(); // New function prototype

int main() {

        int choice;

    while (1) {
        printf("\n=== Contact Management System ===\n");
        printf("1. Add a New Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice\n");
        scanf(" %d", &choice);

        switch (choice) {

            case 1:
               add_contact();
               break;

            case 2:
               display_contacts();
               break;

            case 3:
               printf("Exiting...Goodbye!\n");
               return 0;

            default:
               printf("Error: Invalid choice. Please try again.\n");
    }
}

 return 0;
 
}

void add_contact() {
    // Requesting exact memory from the RAM for one Contact dynamically
    struct Contact *new_contact = (struct Contact *)malloc(sizeof(struct Contact));

    // Checking if the memory was successfully allocated by the OS
    if (new_contact == NULL) {
        printf("Fatal Error: Memory allocation failed. RAM is full!\n");
        return; // Early exit to prevent crash
    }

    // Getting data from the user
    printf("\n--- Enter Contact Details ---\n");

    printf("Enter Name: ");
    while(getchar() != '\n'); 
    scanf(" %[^\n]", new_contact->name);

    printf("Enter Phone: ");
    while(getchar() != '\n'); 
    scanf(" %[^\n], new_contact->phone");

    // Linking the new contact to the front of our linked list
    new_contact->next = head;
    head = new_contact;

    printf("Succes: '%s' has been added to the phonebook!\n", new_contact->name);
}

// New Function Implementation
void display_contacts() {
    // Create a temporary "traveler" pointer and start it at the head
    struct Contact *current = head;

    // Safety check: Is the phonebook completely empty?
    if (current == NULL) {
        printf("\nError: The phonebook is currently empty.\n");
        return;

    }

    printf("\n--- Contact List ---\n");

    // Loop through the list until we run out of contacts (hit NULL)
    while (current !=NULL) {
        // Print the data inside the current node
        printf("Name: %s | Phone: %s\n", current->name, current->phone);

        // The most important step: Move forward to the next node
        current = current->next;
    }

    printf("-------------------\n");

}
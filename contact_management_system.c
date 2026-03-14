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
void display_contacts();
void delete_contact();
void save_contacts();

// A utility funcion to safely clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // EOF = End Of File (No file to read)
}

int main() {

        int choice;

    while (1) {
        printf("\n=== Contact Management System ===\n");
        printf("1. Add a New Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Save Contacts to File\n"); // New Option
        printf("5. Exit\n"); // Shifted Option
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
               delete_contact();
               break;

            case 4:
               save_contacts();
               break;

            case 5:
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

    // Clear the leftover '\n' from the main menu's scanf
    clear_input_buffer();

    // Getting data from the user
    printf("\n--- Enter Contact Details ---\n");

    // Safe input using fgets()
    printf("Enter Name: ");
    fgets(new_contact->name, sizeof(new_contact->name), stdin);

    // Removing the trailing newline character added by fgets
    new_contact->name[strcspn(new_contact->name, "\n")] = '\0';

    // Same here
    printf("Enter Phone: ");
    fgets(new_contact->phone, sizeof(new_contact->phone), stdin);

    new_contact->phone[strcspn(new_contact->phone, "\n")] = '\0';

    // Linking the new contact to the front of our linked list
    new_contact->next = head;
    head = new_contact;

    printf("Succes: '%s' has been added to the phonebook!\n", new_contact->name);
}

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

void delete_contact() {
    // Check if the list is empty
    if (head == NULL) {
        printf("\nError: The phonebook is empty. Nothing to delete!\n");
        return;

    }

    char search_name[50];
    clear_input_buffer(); // Clear the \n left by the menu's scanf

    printf("\nEnter the name of the contact to delete: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = '\0';

    // Setup our two traveler pointers
    struct Contact *current = head;
    struct Contact *previous = NULL;

    // Special Case: If the contact to be deleted is the very first node (head)
    if (strcmp(current->name, search_name) == 0) {
        head = current -> next; // Move the head to the second node
        free(current);          // Give the old head's memory back to the OS
        printf("Success: '%s' has been deleted!\n", search_name);
        return;
    }

    // If we reached the end and (NULL) and didn't find the name
    if (current == NULL) {
        printf("Error: Contact '%s' not found in the phonebook.\n", search_name);
        return;
    }

    // Contact found! Now bridge the gap over 'current'
    previous->next = current->next;

    // Free the memory to prevent Memory Leaks!
    free(current);

    printf("Success: '%s' has been deleted!\n", search_name);
}

// New Function Implementation
void save_contacts() {
    // Open the file in "w" (write) mode
    // "w" mode creates the file if it doesn't exist, or overwrites it if it does.
    FILE *file_ptr = fopen("phonebook_data.txt", "w");

    if (file_ptr == NULL) {
        printf("Error: Could not open file for saving.\n");
        return;
    }

    struct Contact *current = head;
    int count = 0;
}
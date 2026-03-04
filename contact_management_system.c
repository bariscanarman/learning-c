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
    
}
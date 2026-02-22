#include <stdio.h>
#include <string.h>

// Defining the maximum capacity of our library
#define MAX_BOOKS 100

// Defining the Structure for a Book
struct Book {
    int book_id;
    char title[50];   // Allocate 50 just to be safe
    char author[50];  // Same here
    double price;

};

// Function Prototypes
void add_book(struct Book library[], int *count);
void display_books(struct Book library[], int count);

int main () {

    // Creating an array of structures to act as our database
    struct Book library[MAX_BOOKS];

    // A counter to keep track of how many books are currently in the library
    int book_count = 0;
    int choice;

    // Main menu loop
    while (1) {
        printf("\n=== Library Management System ===\n");
        printf("1. Add a New Book\n");
        printf("2. Display All Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               // Passing the array and the momory address of book_count
               add_book(library, &book_count);
               break;

            case 2:
               // Passing the array and the value of book_count
               display_books(library, book_count);
               break;

            case 3:
               printf("Exiting the system. Goodbye\n");
               return 0;

            default:
               printf("Error: Invalid choice.Please try again.\n");
        }

    }

        return 0;

    }

    // Function to add a book
    void add_book(struct Book library[], int *count) {
        // Dereference the pointer to check the actual value
        if (*count >= MAX_BOOKS) {
            printf("Error: Library is full! Cannot add more books.\n");
            return; // Early exit
        }

        printf("\n--- Enter Book Details ---\n");

        printf("Enter Book ID: ");
        scanf("%d", &library[*count].book_id);

        printf("Enter Book Title: ");
        scanf(" %[^\n]", library[*count].title);

        printf("Enter Book Author: ");
        scanf(" %[^\n]", library[*count].author);

        printf("Enter Book Price: ");
        scanf("%lf", &library[*count].price);

        // Dereference the pointer to increment the original book_count in main()
        (*count)++;

        printf("Succes: Book added to the library!\n");
    }

    // Function to display books
    void display_books(struct Book library[], int count) {
        if (count == 0) {
            printf("\nThe library is currently empty.Please add some books first!\n");
            return;
        }

        printf("\n--- List of All Books ---\n");
        for (int i = 0;i < count; i++) {
            printf("Book #%d\n", i + 1);
            printf("  ID     : %d\n", library[i].book_id);
            printf("  Title  : %s\n", library[i].title);
            printf("  Author : %s\n", library[i].author);
            printf("  Price  : %.2lf\n",library[i].price);
            printf("-----------------------\n");
        }
    }


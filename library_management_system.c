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

int main() {

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
               // Check if the library is full before adding
               if (book_count >= MAX_BOOKS) {
                 printf("Error: Library is full! Cannot add more books.\n");
                 break;
              }

               printf("\n--- Enter Book Details ---\n");

               printf("Enter Book ID: ");
               scanf("%d", &library[book_count].book_id);

               // "%[^\n]" tells scanf to read everything including spaces until the Enter key is pressed
               // The space before '%' consumes the leftover newlinr character from the previous scanf
               printf("Enter Book Title: ");
               scanf(" %[^\n]", library[book_count].title);

               printf("Enter Book Author: ");
               scanf(" %[^\n]", library[book_count].author);

               printf("Enter Book Price: ");
               scanf("%lf", &library[book_count].price);

               // Increase the total number of books
               book_count++;
               printf("Succes: Book added to the library!\n");
               break;

            case 2:
               // Not implemented yet
               printf("\n(Display function is coming soon...)\n");
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


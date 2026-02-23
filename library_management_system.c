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

// Function Prototypes updated with search_book
void add_book(struct Book library[], int *count);
void display_books(struct Book library[], int count);
void search_book(struct Book library[], int count);
void save_data(struct Book library[], int count);
void load_data(struct Book library[], int *count);

int main () {

    // Creating an array of structures to act as our database
    struct Book library[MAX_BOOKS];

    // A counter to keep track of how many books are currently in the library
    int book_count = 0;
    int choice;

    // Main menu loop
    while (1) {
        printf("\n=== Library Management System ===\n\n");
        printf("1. Add a New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Save and Exit\n"); // New Option
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
               // Passing the array and the value of book_count, just like display
               search_book(library, book_count);
               break;

            case 4:
               // Save data to the program before exiting the program
               save_data(library, book_count);
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

        printf("\n--- List of All Books ---\n\n");
        for (int i = 0;i < count; i++) {
            printf("Book #%d\n", i + 1);
            printf("  ID     : %d\n", library[i].book_id);
            printf("  Title  : %s\n", library[i].title);
            printf("  Author : %s\n", library[i].author);
            printf("  Price  : %.2lf\n",library[i].price);
            printf("-----------------------\n");
        }
    }

    // New function to search for a book by title
    void search_book(struct Book library[], int count) {
        // Early exit if there are no books to search
       if(count == 0) {
        printf("\nThe library is currently empty.Nothing to search!\n");
        return;
       }

       char search_term[50];
       printf("\nEnter the book title to search: ");
       scanf(" %[^\n]", search_term);

       // A flag variable to track if we found at least one match
       int found = 0;

       printf("\n--- Search Results ---\n");

       // Loop through the entire library
       for(int i = 0; i < count; i++) {
        // strstr checks if 'search_term' is a substring of 'library[i].title'
        // If it is not NULL, it means a match is found
        if (strstr(library[i].title, search_term) != NULL) {
            printf("  ID     : %d\n", library[i].book_id);
            printf("  Title  : %s\n", library[i].title);
            printf("  Author : %s\n", library[i].author);
            printf("  Price  : %.2lf\n",library[i].price);
            printf("-----------------------\n");

            // Set flag to 1 because we found a book
            found = 1;
        }
      }
    
    void save_data(struct Book library[], int count) {
       // Open the file in 'wb' (write binary) mode
       FILE *file_ptr = fopen(FILE_NAME, "wb");
       if(file_ptr == NULL) {
        printf("Error: Could not open file for writing");
        return;
       }
      
       // First save the total number of books we have
       fwrite(&count, sizeof(int), 1, file_ptr);

       // Second, save the entire array of structures in one go
       fwrite(library, sizeof(struct Book), count, file_ptr);

       // Always close the file when done to prevent memory leaks or data loss
       fclose(file_ptr);
       printf("Succes: Data saved to %s succesfully!\n", FILE_NAME);
    }

      // If the loop finishes and found is still 0, print a not-found message
      if(found == 0) {
        printf("No books found matching '%s'.\n", search_term);
      }
    }
       


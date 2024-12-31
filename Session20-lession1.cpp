#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
#include "datatype.h"

struct Book books[MAX_BOOKS];
int bookCount = 0;


void menu() {
    printf("***Book Management System Using C***\n");
    printf("\n");
    printf("               MENU                     \n");
    printf("      =======================\n");
    printf("      [1] Add A New Book.\n");
    printf("      [2] Show All Books.\n");
    printf("      [3] Search A Book.\n");
    printf("      [4] Edit A Book.\n");
    printf("      [5] Delete A Book.\n");
    printf("      [6] Sort Books by Price.\n");
    printf("      [7] Read Books From File");
    printf("      [0] Exit the Program.\n");
    printf("      ==========================\n");
    printf("Enter The Choice: ");
}
void addBook() {
    printf("                         **** Add A New Book ****\n");
    if (bookCount >= MAX_BOOKS) {
        printf("Cannot add book, list is full.\n");
        return;
    }

    struct Book newBook;
    do {
        printf("Enter the Book ID: ");
        scanf("%s", newBook.bookId);
        printf("Enter the Title: ");
        scanf(" %[^\n]%*c", newBook.title);
        printf("Enter the Author: ");
        scanf(" %[^\n]%*c", newBook.author);
        printf("Enter the Quantity: ");
        scanf("%d", &newBook.quantity);
        printf("Enter the Price: ");
        scanf("%d", &newBook.price);
        printf("Enter the Publication Date (dd mm yyyy): ");
        scanf("%d %d %d", &newBook.publication.day, &newBook.publication.month, &newBook.publication.year);
    } while (!isValidBook(newBook)); 

    books[bookCount] = newBook;
    bookCount++;

	saveBooksToFile();
	
    printf("\n");
    printf("Book Added Successfully.\n");
    printf("\n");

    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------\n");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}
void displayBooks() {
   
    if (bookCount == 0) {
        printf("There are no books in the list.\n");
        return;
    }

    printf("                         **** All Books ****\n");
    printf("|============|===========================|======================|============|============|=================|\n");
    printf("| %-10s | %-25s | %-20s | %-10s | %-10s | %-15s |\n", "ID", "Title", "Author", "Quantity", "Price", "Publication");
    printf("|============|===========================|======================|============|============|=================|\n");

	int i;  
    for (i = 0; i < bookCount; i++) {
        printf("| %-10s | %-25s | %-20s | %-10d | %-10d | %02d/%02d/%04d      |\n", 
               books[i].bookId, 
               books[i].title, 
               books[i].author, 
               books[i].quantity, 
               books[i].price,
               books[i].publication.day,
               books[i].publication.month,
               books[i].publication.year);
      
        printf("|------------|---------------------------|----------------------|------------|------------|-----------------|\n");
    }

    printf("\n");
    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
    printf("\n");
    printf("\n");
    printf("\n");
}
//Tiet 2
void editBook() {
    printf("                         **** Edit A Book ****\n");
    char id[10];
    
    printf("Enter the Book ID : ");
    scanf("%s", id);

    int index = -1;
    int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookId, id) == 0) {
            index = i;
            break;
        }
    }
    
  

    if (index == -1) {
        printf("Error: Book with ID '%s' not found.\n", id);
        return;
    }
    
    printf("One Book Found for ID: %s\n\n", books[index].bookId);
	printf("Book Information\n");
	printf("------------------------------\n");
	printf("%-15s: %s\n", "ID", books[index].bookId);
	printf("%-15s: %s\n", "Title", books[index].title);
	printf("%-15s: %s\n", "Author", books[index].author);
	printf("%-15s: %d\n", "Quantity", books[index].quantity);
	printf("%-15s: %d\n", "Price", books[index].price);
	printf("%-15s: %02d/%02d/%04d\n\n", "Publication Date", 
	       books[index].publication.day, 
	       books[index].publication.month, 
	       books[index].publication.year);
	printf("------------------------------\n");
	printf("                  ***************Update The New Book *****\n");
	
    char newTitle[30];
    int titleExists = 0;
    do {
        titleExists = 0; 
        printf("Enter the new Title: ");
        scanf(" %[^\n]%*c", newTitle);

       	int i;
        for (i = 0; i < bookCount; i++) {
            if (i != index && strcmp(books[i].title, newTitle) == 0) {
                printf("Error: Book Title '%s' already exists. Please enter a different title.\n", newTitle);
                titleExists = 1;
                break;
            }
        }
    } while (titleExists);

   
    strcpy(books[index].title, newTitle); 
    printf("Enter the Author: ");
    scanf(" %[^\n]%*c", books[index].author);

    printf("Enter the Quantity: ");
    scanf("%d", &books[index].quantity);

    printf("Enter the Price: ");
    scanf("%d", &books[index].price);

    printf("Enter the Publication Date (dd mm yyyy): ");
    scanf("%d %d %d", &books[index].publication.day, &books[index].publication.month, &books[index].publication.year);

    printf("Book Updated successfully.\n");
 	saveBooksToFile();
  
    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}








    
   

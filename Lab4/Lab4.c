#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    long number;
    char name[30];
    char author[25];
    double price;
} bookT;

void add_book(bookT *library, int LibrarySize);
void edit_book(bookT *library, int LibrarySize);
void display_book(bookT *library, int LibrarySize);
void print_library(bookT *library, int LibrarySize);

int main()
{
    int LibrarySize;
    printf("How many book spaces in library: ");
    scanf("%d", &LibrarySize);

    bookT *library = (bookT *)malloc(sizeof(bookT) * LibrarySize);

    for (int i = 0; i < LibrarySize; i++)
    {
        (library + i)->number = 0;
        strcpy((library + i)->name, "");
        strcpy((library + i)->author, "");
        (library + i)->price = 0;
    }

    while (1)
    {
        printf("1. Find a book\n");
        printf("2. Add a book\n");
        printf("3. Edit a book\n");
        printf("4. Print the library\n");
        printf("-1. Exit\n");

        int choice;
        printf("Pick an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display_book(library, LibrarySize);
            break;

        case 2:
            add_book(library, LibrarySize);
            break;

        case 3:
            edit_book(library, LibrarySize);
            break;

        case 4:
            print_library(library, LibrarySize);
            break;

        case -1:
            exit(0);
            break;
        }
    }

    return 0;
}

void add_book(bookT *library, int LibrarySize)
{
    for (int i = 0; i < LibrarySize; i++)
    {
        if ((library + i)->number == 0)
        {
            printf("Enter book number: ");
            scanf("%ld", &(library + i)->number);

            printf("Enter book name: ");
            scanf("%s", (library + i)->name);

            printf("Enter book author: ");
            scanf("%s", (library + i)->author);

            printf("Enter book price: ");
            scanf("%lf", &(library + i)->price);

            return;
        }
    }

    printf("\nSorry the library is full\n\n");
}

void edit_book(bookT *library, int LibrarySize)
{
    int bookId;
    printf("Book id to edit: ");
    scanf("%d", &bookId);

    for (int i = 0; i < LibrarySize; i++)
    {
        if ((library + i)->number == bookId)
        {
            printf("Enter new book price: ");
            scanf("%lf", &(library + i)->price);

            return;
        }
    }

    printf("\nSorry the library is full\n\n");
}

void display_book(bookT *library, int LibrarySize)
{
    int bookId;
    printf("Book id to display: ");
    scanf("%d", &bookId);

    printf("\n");

    for (int i = 0; i < LibrarySize; i++)
    {
        if ((library + i)->number == bookId)
        {
            printf("Number:\t");
            printf("%ld\n", (library + i)->number);

            printf("Name:\t");
            printf("%s\n", (library + i)->name);

            printf("Author:\t");
            printf("%s\n", (library + i)->author);

            printf("Price:\t");
            printf("%lf\n", (library + i)->price);

            printf("\n");
            return;
        }
    }
}

void print_library(bookT *library, int LibrarySize)
{
    for (int i = 0; i < LibrarySize; i++)
    {
        printf("Book: %d\n", i);

        printf("Number:\t");
        printf("%ld\n", (library + i)->number);

        printf("Name:\t");
        printf("%s\n", (library + i)->name);

        printf("Author:\t");
        printf("%s\n", (library + i)->author);

        printf("Price:\t");
        printf("%lf\n", (library + i)->price);

        printf("\n");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

struct Admin {
    char username[50];
    char password[50];
};

struct Admin admin = {"a", "b"};

struct Student {
    char username[50];
    char password[50];
};

struct Student students[] = 
{
    {"s", "p"},
    {"student2", "pass2"},
    {"student3", "pass3"} 
};

bool isAdminLoggedIn = false;
bool isStudentLoggedIn = false;

void loginAdmin();
void loginStudent();
void printMainMenuForAdmin();
void printMainMenuForStudent();
void clearInputBuffer();
void printStyledMenu();
void printStyledMenuOption();
void printStyledHeading();

void loginAdmin() {
    system("cls");
    char username[50];
    char password[50];

    printf("\n\t\t\t\t\t\t\t\t                 \033[1;36;47m--------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t                     \033[1;33;47m<== \033[1;32;47mAdmin Login \033[1;33;47m==>\n");
    printf("\t\t\t\t\t\t\t\t                 \033[1;36;47m--------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\t                 \033[1;30mEnter Admin Username: ");
    scanf("%s", username);
    printf("\t\t\t\t\t\t\t\t                 \033[1;30mEnter Admin Password: ");
    scanf("%s", password);

    if (strcmp(username, admin.username) == 0 && strcmp(password, admin.password) == 0) {
        isAdminLoggedIn = true;
        printf("\n\t\t\t\t\t\t\t\t\t                 \033[1;33;47m<-- \033[1;32;47mAdmin login successful \033[1;33;47m-->\n\n");
        clearInputBuffer();
        printf("\t\t\t\t\t\t\t\t                 \033[1;30mPress Any Key To Continue...");
        getchar();
        printMainMenuForAdmin();
        
    } else {
        printf("\n\t\t\t\t\t\t\t\t                 \033[1;31mIncorrect username or password for admin.\n\n");
        getchar();

    }
}

void loginStudent() {
    system("cls");
    char username[50];
    char password[50];

    printf("\n\t\t\t\t\t\t\t\t                 \033[1;36;47m--------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t                    \033[1;33;47m<== \033[1;32mStudent Login \033[1;33;47m==>\n");
    printf("\t\t\t\t\t\t\t\t                 \033[1;36;47m--------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\t                 \033[1;37;47mEnter Student Username: ");
    scanf("%s", username);
    printf("\t\t\t\t\t\t\t\t                 \033[1;37;47mEnter Student Password: ");
    scanf("%s", password);

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        if (strcmp(username, students[i].username) == 0 && strcmp(password, students[i].password) == 0) {
            isStudentLoggedIn = true;
            printf("\n\t\t\t\t\t\t\t\t\t                \033[1;33;47m<-- \033[1;32mStudent login successful \033[1;33;47m-->\n\n");
            clearInputBuffer();
            printf("\t\t\t\t\t\t\t\t                 \033[1;30mPress Any Key To Continue...");
            getchar();
            printMainMenuForStudent();
        }
    }
    if(isStudentLoggedIn == false) {
        printf("\n\t\t\t\t\t\t\t\t                 \033[1;31mIncorrect Username or Password for student.\n\n");
    }
}

void headMessage() {
    system("cls");
    printf("\n");
    printStyledMenu("###########################################################################");
    printStyledMenu("#############                                                  ############");
    printStyledMenu("#############      \033[1;33mLibrary management System Project in C      \033[1;30m############");
    printStyledMenu("#############                                                  ############");
    printStyledMenu("###########################################################################");
    printStyledMenu("\033[1;36m---------------------------------------------------------------------------");
    printStyledMenu("    \033[1;30mMade by Anurag, Atharv, Yash Jeswani, Chandan, Ayush and Yash Singh");
    printStyledMenu("\033[1;36m---------------------------------------------------------------------------\n\n");
    printStyledMenu("\033[1;30mPress Enter to continue.....\n\n");
    getchar();
}

struct books {
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
} b;

struct student {
    int id;
    char sName[50];
    char sBranch[50];
    char sRoll[10];
    char bookName[50];
    char date[12];
} s;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

FILE *fp;

void addBook() {
    system("cls");
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(b.date, myDate);

    int nextBookId = 1;

    fp = fopen("books.txt", "ab");

    b.id = nextBookId++;

    printf("\n\n\n\t\t\t\t\t\t\t\t                            \033[1;33;47m<== \033[1;32mAdd Books \033[1;33;47m==>\n");
    printStyledMenu("\t\t-----------------------------------------");

    printf("\t\t\t\t\t\t\t\t                \033[1;30mEnter book name: ");
    fflush(stdin);
    fgets(b.bookName, sizeof(b.bookName), stdin);
    b.bookName[strcspn(b.bookName, "\n")] = '\0';

    printf("\t\t\t\t\t\t\t\t                Enter author name: ");
    fflush(stdin);
    fgets(b.authorName, sizeof(b.authorName), stdin);
    b.authorName[strcspn(b.authorName, "\n")] = '\0';

    printf("\n\t\t\t\t\t\t\t\t\t                \033[1;33m<-- \033[1;32mBook Added Successfully \033[1;33m-->\n");

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
}

void booksList() {
    system("cls");
    printf("\n\t\t\t\t\t\t\t\t                   \033[1;33;47m<== \033[1;32;47mAvailable Books \033[1;33;47m==>\n");
    printf("\t\t\t\t                      \033[1;34;47m----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t                   %-10s %-30s %-20s %s\n\n", "Book id", "Book Name", "Author", "Date");

    fp = fopen("books.txt", "rb");
    while (fread(&b, sizeof(b), 1, fp) == 1) {
        printf("\t\t\t\t\t                   \033[1;37;47m%-10d %-30s %-20s %s\n", b.id, b.bookName, b.authorName, b.date);
    }

    fclose(fp);
    clearInputBuffer();
}

void issueBook() {
    system("cls");
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(s.date, myDate);

    int bookId, found = 0;

    system("cls");
    printf("\n\n\n\t\t\t\t\t\t\t\t                            \033[1;33m<== \033[1;32mIssue Books \033[1;33m==>\n");
    printStyledMenu("\t\t\033[1;36m-----------------------------------------");
    printf("\t\t\t\t\t\t\t\t\t           \033[1;30mEnter Book id to issue: ");
    scanf("%d", &bookId);
    clearInputBuffer();

    fp = fopen("books.txt", "rb");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.id == bookId) {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("\n\t\t\t\t\t\t\t\t                       \033[1;31mNo book found with this id\n");
        printf("\t\t\t\t\t\t\t\t                       \033[1;31mPlease try again...\n\n");
        return;
    }

    FILE *issueFile = fopen("issue.txt", "ab+");

    fseek(issueFile, 0, SEEK_SET);
    while (fread(&s, sizeof(s), 1, issueFile) == 1) {
        if (s.id == bookId) {
            printf("\n\t\t\t\t\t\t\t\t                     \033[1;31mBook with ID %d is already issued.\n", s.id);
            fclose(issueFile);
            return;
        }
    }

    s.id = bookId;
    strcpy(s.bookName, b.bookName);

    printf("\t\t\t\t\t\t\t\t\t           \033[1;30mEnter Student Name: ");
    fgets(s.sName, sizeof(s.sName), stdin);
    s.sName[strcspn(s.sName, "\n")] = '\0';

    printf("\t\t\t\t\t\t\t\t\t           Enter Student Branch: ");
    fgets(s.sBranch, sizeof(s.sBranch), stdin);
    s.sBranch[strcspn(s.sBranch, "\n")] = '\0';

    printf("\t\t\t\t\t\t\t\t\t           Enter Student Roll: ");
    fgets(s.sRoll, sizeof(s.sRoll), stdin);

    printf("\n\n\t\t\t\t\t\t\t\t                      \033[1;33m<-- \033[1;32mBook Issued Successfully \033[1;33m-->\n\n");

    fwrite(&s, sizeof(s), 1, issueFile);
    fclose(issueFile);
}

void del() {
    system("cls");
    int id, f = 0;
    char name[50];
    system("cls");
    printf("\t\t\t\t\t\t\t\t                        \033[1;33m<== \033[1;32mRemove Books \033[1;33m==>\n");
    printStyledMenu("\t\t  -------------------------------");
    printStyledMenuOption(1, "Search by ID");
    printStyledMenuOption(2, "Search by Name");
    printStyledMenuOption(0, "Exit");
    printStyledMenu("\t\t  -------------------------------");
    printf("\t\t\t\t\t\t\t\t\t            Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n\t\t\t\t\t\t\t\t\t\t  Enter Book ID to remove: ");
        scanf("%d", &id);
    } else if (choice == 2) {
        printf("\n\t\t\t\t\t\t\t\t\t\t  Enter Book Name to remove: ");
        fflush(stdin);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
    } else if(choice == 0) {
        return;
        printMainMenuForAdmin();
    }
      else {
        printf("\t\t\t\t\t\t\t\t\t                  \033[1;31mInvalid choice.\n");
        return;
    }

    FILE *ft;

    fp = fopen("books.txt", "rb");

    ft = fopen("temp.txt", "wb");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if ((choice == 1 && id != b.id) || (choice == 2 && strcmp(name, b.bookName) != 0)) {
            fwrite(&b, sizeof(b), 1, ft);
        } else {
            f = 1;
        }
    }

    fclose(fp);
    fclose(ft);

    if (f == 1) {
        remove("books.txt");
        rename("temp.txt", "books.txt");
        printf("\n\t\t\t\t\t\t\t\t\t            \033[1;33m<-- \033[1;32mDeleted Successfully \033[1;33m-->\n");
    } else {
        printf("\n\t\t\t\t\t\t\t\t\t                \033[1;31mRecord Not Found !\n\n");
    }
}

void returnBook() {
    int id, found = 0;

    system("cls");
    printf("\n\n\n\t\t\t\t\t\t\t\t                            \033[1;33m<== \033[1;32mReturn Book \033[1;33m==>\n");
    printStyledMenu("\t\t\033[1;36m-----------------------------------------");\
    printf("\t\t\t\t\t\t\t\t                      \033[1;30mEnter Book id to return: ");
    scanf("%d", &id);
    clearInputBuffer();

    FILE *issueFile = fopen("issue.txt", "rb");

    FILE *tempFile = fopen("temp.txt", "wb");

    while (fread(&s, sizeof(s), 1, issueFile) == 1) {
        if (s.id == id) {
            found = 1;
            printf("\n\n\t\t\t\t\t\t\t\t           \033[1;32mBook '%s' returned by student '%s'\n", s.bookName, s.sName);
        } else {
            fwrite(&s, sizeof(s), 1, tempFile);
        }
    }

    fclose(issueFile);
    fclose(tempFile);

    remove("issue.txt");
    rename("temp.txt", "issue.txt");

    if (!found) {
        printf("\n\t\t\t\t\t\t\t\t                      \033[1;31mBook with ID %d is not issued.\n", id);
    }
}

void issueList() {
    system("cls");
    printf("\n\t\t\t\t\t\t\t\t\t                   \033[1;33m<== \033[1;32mBook Issue List \033[1;33m==>\n");
    printf("\t\t\t\t                 \033[1;34;47m---------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t                   \033[1;30m%-10s %-20s %-20s %-20s %-30s %s\n", "S.id", "Name", "Branch", "Roll", "Book Name", "Date");

    FILE *issueFile = fopen("issue.txt", "rb");

    while (fread(&s, sizeof(s), 1, issueFile) == 1) {
        printf("\n\t\t\t\t                   \033[1;30m%-10d %-20s %-20s %-20s %-30s %s\n", s.id, s.sName, s.sBranch, s.sRoll, s.bookName, s.date);
    }

    fclose(issueFile);
}

void printStyledMenuOption(int optionNumber, const char *optionText) {
    printf("\t\t\t\t\t\t\t\t\t                \033[1;36;47m%d. \033[1;37;47m%s\n", optionNumber, optionText);
}

void printStyledMenu(const char *optionText) {
    printf("\t\t\t\t\t\t\t\t\033[1;47m%s\n", optionText);
}

void printStyledHeading(const char *optionText) {
    printf("\t\t\t\t\t\t\t\t              \033[1;33;47m<== \033[1;32;47m%s \033[1;33;47m==>\n", optionText);
}

void printMainMenuForAdmin() {
    system("cls");
    printStyledMenu("\t\t\033[1;33m<== \033[1;32mLibrary Management System (Admin) \033[1;33m==>");
    printStyledMenu("\t\t\033[1;36m-----------------------------------------");
    printStyledMenu("\t\t\t  \033[1;33m<-- \033[1;30mWelcome Admin \033[1;33m-->");
    printStyledMenu("\t\t\033[1;36m-----------------------------------------");
    printStyledMenuOption(1, "Add Book");
    printStyledMenuOption(2, "Books List");
    printStyledMenuOption(3, "Remove Book");
    printStyledMenuOption(4, "Issue Book");
    printStyledMenuOption(5, "Return Book");
    printStyledMenuOption(6, "Issued Book List");
    printStyledMenuOption(0, "Logout");
    printStyledMenu("\t\t\033[1;36m-----------------------------------------");
    printf("\t\t\t\t\t\t\t\t\t\t\033[1;30mEnter your choice: ");
}

void printMainMenuForStudent() {
    system("cls");
    printf("\t\t\t\t\t\t\t\t                   \033[1;33;47m<== \033[1;32;47mLibrary Management System (Student) \033[1;33;47m==>\n");
    printf("\t\t\t\t\t\t\t\t                 \033[1;36;47m-----------------------------------------------\n");
    printStyledMenu("\t\t\t     \033[1;33m<-- \033[1;30mWelcome Student \033[1;33m-->");
    printf("\t\t\t\t\t\t\t\t                 \033[1;36;47m-----------------------------------------------\n");
    printStyledMenuOption(1, "Books List");
    printStyledMenuOption(2, "Issue Book");
    printStyledMenuOption(3, "Return Book");
    printStyledMenuOption(0, "Logout");
    printf("\t\t\t\t\t\t\t\t                 \033[1;36;47m-----------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t                   \033[1;30;47mEnter your choice: ");
}

int main() {
    printf("\033[1;47m");
    headMessage();
    system("cls");

    int choice;
    int isAdmin = 0;
    int isStudent = 0;

    while (1) {
        printStyledMenu("\t    \033[1;36m----------------------------------------------------");
        printStyledHeading("Welcome to the Library Management System");
        printStyledMenu("\t    \033[1;36m----------------------------------------------------\n");
        printStyledMenuOption(1, "Admin Login");
        printStyledMenuOption(2, "Student Login");
        printStyledMenuOption(0, "Exit\n");
        printStyledMenu("\t    \033[1;36m----------------------------------------------------");
        printf("\t\t\t\t\t\t\t\t\t\t\033[1;30mEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                exit(0);
            case 1:
                loginAdmin();
                if (isAdminLoggedIn) {
                    isAdmin = 1;
                }
                break;
            case 2:
                loginStudent();
                if (isStudentLoggedIn) {
                    isStudent = 1;
                }
                break;
            default:
                printf("\n\t\t\t\t\t\t\t\t                   \033[1;31mInvalid choice.\n\n");
        }

        if (isAdmin || isStudent) {
            break;
        }
    }

    int ch;

    if (isAdmin) {
        while (1) {
            scanf("%d", &ch);

            switch (ch) {
                case 0:
                    exit(0);
                case 1:
                    addBook();
                    break;
                case 2:
                    booksList();
                    break;
                case 3:
                    del();
                    break;
                case 4:
                    issueBook();
                    break;
                case 5:
                    returnBook();
                    break;
                case 6:
                    issueList();
                    break;
                default:
                    printf("\t\t\t\t\t\t\t\t                   \033[1;31mInvalid Choice...\n\n");
            }

            clearInputBuffer();
            printf("\n\t\t\t\t\t\t\t\t                   \033[1;30mPress Any Key To Continue...");
            getchar();
            printMainMenuForAdmin();
        }
    } 
    else if (isStudent) {
        while (1) {
            scanf("%d", &ch);

            switch (ch) {
                case 0:
                    exit(0);
                case 1:
                    booksList();
                    break;
                case 2:
                    issueBook();
                    break;
                case 3:
                    returnBook();
                    break;
                default:
                    printf("\t\t\t\t\t\t\t\t                   \033[1;37;47mInvalid Choice...\n\n");
            }


        clearInputBuffer();
        printf("\t\t\t\t\t\t\t\t                   \033[1;30mPress Any Key To Continue...");
        getchar();
        printMainMenuForStudent();
        }
    }

    return 0;
}

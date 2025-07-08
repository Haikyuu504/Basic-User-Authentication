#include <stdio.h>
#include <string.h>

int main() {
    int option;
    char registeredEmail[100] = "";
    char registeredPassword[100] = "";
    char loggedInEmail[100] = "";
    int isRegistered = 0;
    int isLoggedIn = 0;

    while (1) {
        printf("1. Register Account\n");
        printf("2. Login Account\n");
        printf("3. Account Info\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("Register Email: ");
            scanf("%s", registeredEmail);

            int len = strlen(registeredEmail);
            if (len >= 10 && strcmp(&registeredEmail[len - 10], "@gmail.com") == 0) {
                printf("Register Password: ");
                scanf("%s", registeredPassword);
                printf("Registered successfully!\n");
                isRegistered = 1;
            } else {
                printf("ERROR: Email must contain '@gmail.com'\n");
                registeredEmail[0] = '\0';
                registeredPassword[0] = '\0';
                isRegistered = 0;
            }

        } else if (option == 2) {
            if (!isRegistered) {
                printf("No user registered. Please register first.\n");
                continue;
            }

            char inputEmail[100];
            char inputPassword[100];

            printf("Enter Email: ");
            scanf("%s", inputEmail);

            printf("Enter Password: ");
            scanf("%s", inputPassword);

            if (strcmp(inputEmail, registeredEmail) == 0 && strcmp(inputPassword, registeredPassword) == 0) {
                strcpy(loggedInEmail, inputEmail);
                isLoggedIn = 1;
                printf("Login successful. Welcome!\n");
            } else {
                printf("Login failed. Email or password is incorrect.\n");
            }

        } else if (option == 3) {
            if (isLoggedIn) {
                printf("Account Info:\n");
                printf("Email: %s\n", loggedInEmail);
            } else {
                printf("You are not logged in. Please login first.\n");
            }

        } else if (option == 4) {
            printf("Goodbye!\n");
            break;

        } else {
            printf("Invalid option. Please choose 1-4.\n");
        }
    }

    return 0;
}

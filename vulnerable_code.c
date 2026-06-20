#include <stdio.h>
#include <string.h>

void login() {
    char password[10]; // Allocates 10 bytes of memory
    
    printf("Enter your password: ");
    //Vulnerability: gets() does not check for input bounds
    gets(password); 

    if (strcmp(password, "Secure123") == 0) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }
}

int main() {
    login();
    return 0;
}

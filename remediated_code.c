#include <stdio.h>
#include <string.h>

void login() {
    char password[10]; 
    
    printf("Enter your password: ");
    
    // Remediation: fgets ensures a strict maximum input size limit to prevent buffer overflow
    if (fgets(password, sizeof(password), stdin) != NULL) {
        
        // Remove trailing newline character
        password[strcspn(password, "\n")] = '\0';

        if (strcmp(password, "Secure123") == 0) {
            printf("Access Granted!\n");
        } else {
            printf("Access Denied.\n");
        }
    }
}

int main() {
    login();
    return 0;
}

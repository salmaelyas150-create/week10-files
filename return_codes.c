
#include <stdio.h>
#include <errno.h>
#include <string.h>

// Function returns 0 for success and 1 for failure
int readFileWithReturnCode(const char *filename) {

    FILE *file = fopen(filename, "r");

    if (file == NULL) {

        // Display error using stderr
        fprintf(stderr, "Error opening file: %s\n",
                strerror(errno));

        return 1;
    }

    // File opened successfully
    printf("File opened successfully!\n");

    fclose(file);

    return 0;
}

int main() {

    printf("--- Testing Return Code Strategy ---\n");

    // Check the returned status
    if (readFileWithReturnCode("data.txt") == 1) {
        printf("Main function: Handled error gracefully. Program continues.\n");
    }

    printf("\n--- Evaluation ---\n");

    printf("In C, we must manually check return codes.\n");

    printf("If the programmer forgets to check, the program might crash later.\n");

    return 0;
}

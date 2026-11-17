
#include <stdio.h>

int main() {

    // Try to open a file that does not exist
    FILE *myFile = fopen("missing_file.txt", "r");

    // No NULL check is performed

    char data[100];

    printf("Attempting to read from missing file...\n");

    // Attempt to read using an invalid file pointer
    fscanf(myFile, "%99s", data);

    printf("Data read: %s\n", data);

    fclose(myFile);

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {

    FILE *file = fopen("students.csv", "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not find students.csv!\n");
        return 1;
    }

    char line[100];

    printf("--- Processing Student Records ---\n");

    // Read file line by line
    while (fgets(line, sizeof(line), file)) {

        char name[20];
        char scoreStr1[10];
        char scoreStr2[10];
        char scoreStr3[10];

        int s1, s2, s3;

        // Parse CSV line
        int itemsRead = sscanf(
            line,
            "%19[^,],%9[^,],%9[^,],%9[^\n]",
            name,
            scoreStr1,
            scoreStr2,
            scoreStr3
        );

        if (itemsRead != 4) {
            printf("WARNING: Skipping malformed line format: %s", line);
            continue;
        }

        // Convert scores into integers
        int valid1 = sscanf(scoreStr1, "%d", &s1);
        int valid2 = sscanf(scoreStr2, "%d", &s2);
        int valid3 = sscanf(scoreStr3, "%d", &s3);

        if (valid1 == 1 && valid2 == 1 && valid3 == 1) {

            // Calculate average
            double average = (s1 + s2 + s3) / 3.0;

            printf("%s -> Average: %.2f\n", name, average);

        } else {

            printf("WARNING: Skipping malformed record for %s (Invalid score data).\n", name);
        }
    }

    fclose(file);

    printf("\n--- Processing Complete ---\n");

    return 0;
}

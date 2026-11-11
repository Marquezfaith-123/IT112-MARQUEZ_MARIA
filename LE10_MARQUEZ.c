
#include <stdio.h>

int main() {
    FILE *file;
    char note[500];
    int n, i;

    // Create the file and write initial notes
    file = fopen("notes.txt", "w");

    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    printf("Writing Notes File:\n");
    printf("How many notes do you want to record? ");
    scanf("%d", &n);
    getchar();

    for (i = 1; i <= n; i++) {
        printf("\nNote %d: ", i);
        fgets(note, sizeof(note), stdin);
        fprintf(file, "%s", note);
    }

    fclose(file);

    printf("\nInitial notes saved successfully.\n");

    // Append one additional note
    file = fopen("notes.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nEnter one additional note:\n");
    fgets(note, sizeof(note), stdin);
    fprintf(file, "%s", note);

    fclose(file);

    printf("\nNew note added successfully.\n");

    // Read and display all saved notes
    file = fopen("notes.txt", "r");

    if (file == NULL) {
        printf("Error reading file!\n");
        return 1;
    }

    printf("\nReading Saved Notes:\n");

    i = 1;
    while (fgets(note, sizeof(note), file) != NULL) {
        printf("%d. %s", i, note);
        i++;
    }

    fclose(file);

    return 0;
}
#include <stdio.h>

int main() {
    FILE *fp;                 // file pointer

    // Open file in write mode ("w")
    fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("Cannot open file for writing.\n");
        return 1;
    }

    fprintf(fp, "Hello. This is a test file.\n");
    fclose(fp);               // close file after writing

    // Reopen file in read mode ("r")
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file for reading.\n");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);               // close file after reading
    return 0;
}

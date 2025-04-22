#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            printf("'%c' is a letter\n", ch);
        } else if (isdigit(ch)) {
            printf("'%c' is a digit\n", ch);
        } else if (isspace(ch)) {
            continue;
        } else {
            printf("'%c' is a special symbol\n", ch);
        }
    }

    fclose(fp);
    return 0;
}

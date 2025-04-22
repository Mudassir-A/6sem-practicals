#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

void S() {
    if (input[i] == 'a') {
        i++;
        S();
        if (input[i] == 'b') {
            i++;
        } else {
            printf("Invalid String.\n");
            exit(0);
        }
    }
}

int main() {
    printf("Enter a string: ");
    scanf("%s", input);

    S();

    if (input[i] == '\0') {
        printf("Valid String.\n");
    } else {
        printf("Invalid String.\n");
    }

    return 0;
}

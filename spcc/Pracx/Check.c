#include <stdio.h>
#include <ctype.h>

int main() {
    char str[50];
    int i = 0, dot = 0, valid = 1;

    printf("Enter a number: ");
    scanf("%s", str);

    while (str[i]) {
        if (isdigit(str[i])) {
            i++;
        } else if (str[i] == '.') {
            dot++;
            if (dot > 1) {
                valid = 0;
                break;
            }
            i++;
        } else {
            valid = 0;
            break;
        }
    }

    if (valid) {
        if (dot == 1)
            printf("Floating point number.\n");
        else
            printf("Integer number.\n");
    } else {
        printf("Invalid number format.\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char label[10], opcode[10], operand[10];
    int locctr = 1000;

    printf("Enter LABEL OPCODE OPERAND (type END to stop):\n");

    while (1) {
        scanf("%s", label);
        if (strcmp(label, "END") == 0) break;
        scanf("%s %s", opcode, operand);

        printf("%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
        locctr += 3;
    }

    return 0;
}

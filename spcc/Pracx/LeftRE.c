#include <stdio.h>

int main() {
    char nonTerminal = 'A';
    char alpha[] = "a";
    char beta[] = "b";

    printf("Original Grammar: %c -> %c%s | %s\n", nonTerminal, nonTerminal, alpha, beta);
    printf("Eliminating Left Recursion...\n");

    printf("New Grammar:\n");
    printf("%c -> %s%c'\n", nonTerminal, beta, nonTerminal);
    printf("%c' -> %s%c' | ε\n", nonTerminal, alpha, nonTerminal);

    return 0;
}

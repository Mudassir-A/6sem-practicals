#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

int main()
{
	char non_terminal;
	char productions[MAX][MAX], alpha[MAX][MAX], beta[MAX][MAX];
	int n, i, ac = 0, bc = 0;

	printf("Enter the non-terminal: ");
	scanf(" %c", &non_terminal);

	printf("Enter number of productions for %c: ", non_terminal);
	scanf("%d", &n);

	printf("Enter productions (without spaces, use '|' as input separator, like Aα or β):\n");
	for (i = 0; i < n; i++)
	{
		printf("%c → ", non_terminal);
		scanf("%s", productions[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (productions[i][0] == non_terminal)
		{
			// Left recursive: A → Aα → store α
			strcpy(alpha[ac], productions[i] + 1);
			ac++;
		}
		else
		{
			// Non-left-recursive: A → β → store β
			strcpy(beta[bc], productions[i]);
			bc++;
		}
	}

	if (ac == 0)
	{
		printf("\nNo left recursion found.\n");
		return 0;
	}

	// Output new productions
	printf("\nAfter eliminating left recursion:\n");

	// A → βA'
	for (i = 0; i < bc; i++)
	{
		printf("%c → %s%c'\n", non_terminal, beta[i], non_terminal);
	}

	// A' → αA' | ε
	printf("%c' → ", non_terminal);
	for (i = 0; i < ac; i++)
	{
		printf("%s%c'", alpha[i], non_terminal);
		if (i != ac - 1)
			printf(" | ");
	}
	printf(" | ε\n");

	return 0;
}

#include <stdio.h>
#include <string.h>

int main()
{
	char str[200];
	int count = 0, i;

	printf("Enter a string: ");
	scanf("%[^\n]s", str);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			count++;
	}

	printf("Number of words in the given sentence: %d\n", count + 1);

	return 0;
}
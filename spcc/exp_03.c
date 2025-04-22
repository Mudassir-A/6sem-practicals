#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const char *input;
int pos = 0;

// Function declarations
int E(), Eprime(), T(), Tprime(), F();

void error()
{
	printf("Syntax Error at position %d\n", pos);
	exit(1);
}

int match(char expected)
{
	if (input[pos] == expected)
	{
		pos++;
		return 1;
	}
	return 0;
}

// E → T E'
int E()
{
	if (T())
	{
		if (Eprime())
			return 1;
	}
	return 0;
}

// E' → + T E' | ε
int Eprime()
{
	if (input[pos] == '+')
	{
		pos++;
		if (T())
		{
			if (Eprime())
				return 1;
			else
				error();
		}
		else
			error();
	}
	return 1; // ε (empty) production
}

// T → F T'
int T()
{
	if (F())
	{
		if (Tprime())
			return 1;
	}
	return 0;
}

// T' → * F T' | ε
int Tprime()
{
	if (input[pos] == '*')
	{
		pos++;
		if (F())
		{
			if (Tprime())
				return 1;
			else
				error();
		}
		else
			error();
	}
	return 1; // ε
}

// F → ( E ) | id
int F()
{
	if (match('('))
	{
		if (E())
		{
			if (match(')'))
				return 1;
			else
				error();
		}
		else
			error();
	}
	else if (isalpha(input[pos]))
	{
		pos++;
		return 1;
	}
	return 0;
}

int main()
{
	char buffer[100];

	printf("Enter expression (use 'id' as single letters like a, b, etc): ");
	scanf("%s", buffer);
	input = buffer;

	if (E() && input[pos] == '\0')
	{
		printf("Parsing successful.\n");
	}
	else
	{
		error();
	}

	return 0;
}

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[32][10] = {
	"int", "float", "char", "if", "else", "while", "do", "for", "return", "break",
	"continue", "void", "static", "struct", "switch", "case", "default", "long",
	"double", "short", "unsigned", "signed", "sizeof", "typedef", "union", "const",
	"enum", "goto", "register", "volatile", "extern", "auto"};

int isKeyword(char *str)
{
	for (int i = 0; i < 32; i++)
	{
		if (strcmp(str, keywords[i]) == 0)
			return 1;
	}
	return 0;
}

int main()
{
	char ch, buffer[50];
	int i = 0;
	FILE *fp = fopen("source.c", "r");

	if (!fp)
	{
		printf("Could not open source file.\n");
		return 1;
	}

	printf("Tokens:\n");

	while ((ch = fgetc(fp)) != EOF)
	{
		// Identifiers / Keywords
		if (isalpha(ch) || ch == '_')
		{
			buffer[i++] = ch;
			while (isalnum(ch = fgetc(fp)) || ch == '_')
				buffer[i++] = ch;
			buffer[i] = '\0';
			i = 0;
			ungetc(ch, fp);

			if (isKeyword(buffer))
				printf("<Keyword\t%s>\n", buffer);
			else
				printf("<Identifier\t%s>\n", buffer);
		}

		// Numbers
		else if (isdigit(ch))
		{
			buffer[i++] = ch;
			while (isdigit(ch = fgetc(fp)))
				buffer[i++] = ch;
			buffer[i] = '\0';
			i = 0;
			ungetc(ch, fp);
			printf("<Number\t\t%s>\n", buffer);
		}

		// Operators
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>' || ch == '<')
		{
			char next = fgetc(fp);
			if ((ch == '=' && next == '=') ||
				(ch == '!' && next == '=') ||
				(ch == '<' && next == '=') ||
				(ch == '>' && next == '='))
			{
				printf("<Operator\t%c%c>\n", ch, next);
			}
			else
			{
				ungetc(next, fp);
				printf("<Operator\t%c>\n", ch);
			}
		}

		// Special characters
		else if (ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
				 ch == ';' || ch == ',' || ch == '[' || ch == ']')
		{
			printf("<Special\t%c>\n", ch);
		}
	}

	fclose(fp);
	return 0;
}

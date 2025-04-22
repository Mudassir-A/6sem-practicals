#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct opcode
{
	char mnemonic[10];
	char code[10];
};

struct symbol
{
	char label[10];
	int address;
};

struct opcode optab[] = {
	{"MOV", "01"},
	{"ADD", "02"},
	{"SUB", "03"},
	{"JMP", "04"},
	{"END", "00"},
	{"START", "05"},
	{"", ""}};

struct symbol symtab[MAX];
int sym_count = 0;

int search_symtab(char *label)
{
	for (int i = 0; i < sym_count; i++)
	{
		if (strcmp(symtab[i].label, label) == 0)
			return i;
	}
	return -1;
}

void add_symtab(char *label, int addr)
{
	strcpy(symtab[sym_count].label, label);
	symtab[sym_count].address = addr;
	sym_count++;
}

char *get_opcode(char *mnemonic)
{
	for (int i = 0; optab[i].mnemonic[0] != '\0'; i++)
	{
		if (strcmp(optab[i].mnemonic, mnemonic) == 0)
			return optab[i].code;
	}
	return NULL;
}

int main()
{
	FILE *fp;
	char line[50], label[10], opcode[10], operand[10];
	int locctr = 0, start = 0;

	fp = fopen("input.asm", "r");
	if (!fp)
	{
		printf("File not found.\n");
		return 1;
	}

	printf("Intermediate Code:\n");
	printf("Loc\tOpcode\tOperand\n");

	while (fgets(line, sizeof(line), fp))
	{
		int count = sscanf(line, "%s %s %s", label, opcode, operand);
		if (count == 3)
		{
			if (strcmp(opcode, "START") == 0)
			{
				start = atoi(operand);
				locctr = start;
				printf("%d\t%s\t%s\n", locctr, opcode, operand);
				continue;
			}

			if (search_symtab(label) == -1)
			{
				add_symtab(label, locctr);
			}
		}
		else if (count == 2)
		{
			strcpy(opcode, label);
			strcpy(operand, opcode);
			label[0] = '\0';
		}

		char *code = get_opcode(opcode);
		if (code)
		{
			printf("%d\t%s\t%s\n", locctr, code, operand);
			locctr += 1;
		}
		else if (strcmp(opcode, "END") == 0)
		{
			printf("%d\t%s\t%s\n", locctr, opcode, operand);
			break;
		}
		else
		{
			printf("Invalid opcode %s\n", opcode);
		}
	}

	fclose(fp);

	printf("\nSymbol Table:\n");
	for (int i = 0; i < sym_count; i++)
	{
		printf("%s\t%d\n", symtab[i].label, symtab[i].address);
	}

	return 0;
}

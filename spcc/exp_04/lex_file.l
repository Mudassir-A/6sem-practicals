%{
	#include <stdio.h>
	#include <stdlib.h>

	// Declare the file pointer for input (will be set to input.txt)
	extern FILE *yyin;
	extern int yylex();
	extern char *yytext;
%}

%%
	int { printf("Keyword: int\n"); }
	[a-zA-Z]+ { printf("Identifier: %s\n", yytext); }
	[0-9]+ { printf("Integer: %s\n", yytext); }
	"=" { printf("Operator: =\n"); }
	";" { printf("Semicolon: ;\n"); }
	"+" { printf("Operator: +\n"); }
	"-" { printf("Operator: -\n"); }
	"*" { printf("Operator: *\n"); }
	"/" { printf("Operator: /\n"); }
	"(" { printf("Left Parenthesis: (\n"); }
	")" { printf("Right Parenthesis: )\n"); }
	[ \t\n] { /* Ignore whitespace */ }
	. { printf("Unknown character: %s\n", yytext); }
%%

// Main function that opens the input file
int main(int argc, char *argv[]) {
	if (argc > 1) {
		// If a file name is provided as an argument, open the file
		yyin = fopen(argv[1], "r");
		
		if (yyin == NULL) {
			fprintf(stderr, "Error opening file %s\n", argv[1]);
			return 1;
		}
	} else {
		// If no file is provided, print an error and return
		fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
		return 1;
	}
	yylex(); // Call the lexical analyzer to start processing the input file
	fclose(yyin); // Close the input file after processing
	return 0;
}

int yywrap() { return 1; }
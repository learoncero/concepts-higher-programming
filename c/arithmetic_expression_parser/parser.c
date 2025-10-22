#include <stdio.h>
#include <stdbool.h>

typedef enum {
	noSy,
	eolSy,
	errSy,
	numSy,
	plusSy,
	minusSy,
	multSy,
	powSy,
	assignSy,
	lParenSy,
	rParenSy
} symbol_t;

const char* expression = "(5+2)*3=";

int pos = 0;
char ch;
bool success = true;
symbol_t sy = noSy;
int number = 0;

// Forward declaration
void nextChar();
void newSy();
int expr();
int factor();
int term();
void printSymbol(symbol_t symbol);

void nextChar() {
	ch = expression[pos++];
}

void newSy() { // Lexikalischer Analysator, der das nächste Symbol in Eingabestrom erzeugt
	sy = noSy;
	
	while (sy == noSy) {
		switch (ch) {
		case (' '):
			nextChar();
			break;

		case ('+'):
			sy = plusSy;
			nextChar();
			break;

		case ('-'):
			sy = minusSy;
			nextChar();
			break;

		case ('*'):
			sy = multSy;
			nextChar();

			if (ch == '*') {
				sy = powSy;
				nextChar();
			}

			break;

		case ('\0'):
			sy = eolSy;
			break;

		case ('='):
			sy = assignSy;
			nextChar();
			break;

		case ('('):
			sy = lParenSy;
			nextChar();
			break;

		case (')'):
			sy = rParenSy;
			nextChar();
			break;

		default:
			if (ch >= '0' && ch <= '9') {
				number = 0;
				while (ch >= '0' && ch <= '9') {
					number = (number * 10) + (ch - '0');
					sy = numSy;
					nextChar();
				}
			}
			else {
				sy = errSy;
				nextChar();
			}
			
			break;
		}
	}
}

void printSymbol(symbol_t symbol) {
	switch (symbol) {
	case plusSy:
		printf("plusSy ");
		break;

	case minusSy:
		printf("minusSy ");
		break;

	case assignSy:
		printf("assignSy ");
		break;

	case eolSy:
		printf("eolSy ");
		break;

	case numSy:
		printf("numSy ");
		break;

	case multSy:
		printf("multSy ");
		break;

	case powSy:
		printf("powSy ");
		break;

	case errSy:
		printf("Lex Error: illegal character! ");
		break;

	case lParenSy:
		printf("lParenSy ");
		break;

	case rParenSy:
		printf("rParenSy ");
		break;

	default:
		printf("noSy ");
		break;
	}
}

// Grammar: factor -> numSy | ( expr )
int factor() {
	int result = 0;

	switch (sy) {
	case (numSy):
		printSymbol(sy);
		result = number;
		newSy();

		// sem
		return result;
		// endsem
		break;

	case (lParenSy):
		printSymbol(sy);
		newSy();
		result = expr();

		if (sy != rParenSy) {
			success = false;
			printf("\nSyntax Error: expected ')'! ");
			return 0;
		}

		newSy();
		break;

	default:
		success = false;
		printf("\nSyntax Error: expected number or '('. ");
		return 0;
	}

	// sem
	return result;
	// endsem
}

// Grammar: term -> factor | term * factor
int term() {
	// sem
	int op1 = 0;
	// endsem

	op1 = factor(); // Parse first factor

	if (!success) {
		return 0;
	}

	// Handle multiplication
	while (sy == multSy) {
		// sem
		int op2 = 0;
		// endsem

		printSymbol(sy);
		newSy();

		op2 = factor(); // Parse next factor

		if (!success) {
			return 0;
		}

		// sem
		op1 = op1 * op2;
		// endsem
	}

	// sem
	return op1;
	// endsem
}

// Grammar: expr -> term | { expr (plusSy | minusSy) term }
int expr() {
	// sem
	int op1 = 0;
	// endsem

	op1 = term();

	if (!success) {
		return 0;
	}

	// Handle addition and subtraction (recursive)
	while ((sy == plusSy) || (sy == minusSy)) {
		symbol_t operator = sy;

		// sem
		int op2 = 0;
		// endsem

		printSymbol(sy);
		newSy();

		op2 = term(); //recursively processes the rest

		if (!success) {
			return 0;
		}

		// sem
		if (operator == plusSy) {
			op1 = op1 + op2;
		}
		else if (operator == minusSy) {
			op1 = op1 - op2;
		}
		// endsem
	}

	// Check for assignment or end of line
	if (sy == assignSy) {
		printSymbol(sy);
		newSy();
	}

	if (sy != eolSy && sy != rParenSy) {
		success = false;
		printf("\nSyntax Error: unexpected symbol after expression!");
		return 0;
	}

	printSymbol(sy);

	// sem
	return op1;
	// endsem
}

int main() {
	nextChar();
	newSy();

	int result = expr();

	if (!success) {
		printf("\nParsing failed.\n");
	}
	else {
		printf("\nParsing succeeded. Result = %d\n", result);
	}

	return 0;
}
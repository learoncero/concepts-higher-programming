#include <stdio.h>

typedef enum {
	noSy,
	eolSy,
	errSy,
	numSy,
	plusSy,
	multSy,
	powSy,
	assignSy,
} symbol_t;

const char* expression = "1**2*5=@";
int pos = 0;
char ch;

char nextChar() {
	return expression[pos++];
}

symbol_t newSy() { // Lexikalischer Analysator, der das nächste Symbol in Eingabestrom erzeugt
	symbol_t sy = noSy;

	while (sy == noSy) {
		switch (ch) {
		case (' '):
			ch = nextChar();
			break;

		case '+':
			sy = plusSy;
			ch = nextChar();
			break;

		case '*':
			sy = multSy;
			ch = nextChar();

			if (ch == '*') {
				sy = powSy;
				ch = nextChar();
			}

			break;
		case ('\0'):
			sy = eolSy;
			break;

		case ('='):
			sy = assignSy;
			ch = nextChar();
			break;

		default:
			if (ch >= '0' && ch <= '9') {
				while (ch >= '0' && ch <= '9') {
					sy = numSy;
					ch = nextChar();
				}
			}
			else {
				sy = errSy;
				ch = nextChar();
			}
			
			break;
		}
	}

	return sy;
}

void printSymbol(symbol_t symbol) {
	switch (symbol) {
	case plusSy:
		printf("plusSy ");
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

	default:
		printf("noSy ");
		break;
	}
}

int main() {
	ch = nextChar();
	symbol_t symbol = noSy;
	while (symbol != eolSy) {
		symbol = newSy();
		printSymbol(symbol);
	}

	return 0;
}
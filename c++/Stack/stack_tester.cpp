#include <iostream>
#include <stdlib.h>
#include "stack.hpp"
using namespace std; // somit muss man nicht std::cout schreiben

int main() {
	// Variante 1
	// hier allokiert man statisch, man muss sich nicht um den Speicher kümmern
	{
		Stack s;
		Stack s1(2);

		s.push(10);
		s.push(12);

		while (!s.isEmpty()) {
			cout << s.pop() << endl;
		}

		s1.push(10);
		s1.push(12);
		s1.push(14);

		while (!s.isEmpty()) {
			cout << s.pop() << endl;
		}
	}
	
	// Variante 2
	// hier allokiert man dynamisch und man muss den Speicher selbst reservieren/freigeben
	{
		Stack * const s = new Stack(); 

		s->push(10);
		s->push(12);
		//(*s).push(13);

		while (!s->isEmpty()) {
			cout << s->pop() << endl;
		}

		delete s; // wie "free" in c
		s = nullptr; // dangling pointer vermeiden
	}

	// Variante 3
	// Aliasing
	{
		Stack s1;
		Stack& s = s1; // s ist eine Referenz auf die Stelle, an der s1 im Speicher abgelegt ist

		s.push(10);
		s.push(12);

		while (!s.isEmpty()) {
			cout << s.pop() << endl;
		}
	}

	return 0;
}
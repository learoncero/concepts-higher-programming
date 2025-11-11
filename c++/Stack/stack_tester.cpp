#include <iostream>
#include <stdlib.h>
#include "stack.hpp"
using namespace std; // somit muss man nicht std::cout schreiben

Stack i() {
	Stack s(100);
	s.push(42);

	return s;

}

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

		while (!s1.isEmpty()) {  // FIX: war s.isEmpty() - sollte s1 sein
			cout << s1.pop() << endl;  // FIX: war s.pop() - sollte s1 sein
		}
	}
	
	// Variante 2
	// hier allokiert man dynamisch und man muss den Speicher selbst reservieren/freigeben
	{
		Stack * s = new Stack(); 

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

	// Call by Value Beispiel - Funktioniert so nicht
	{
		/*Stack s3;
		s3.f(s3);

		while (!s3.isEmpty()) {
			cout << s3.pop() << endl;
		}*/
	}

	// Call by Reference
	{
		Stack s4;
		s4.h(s4);

		while (!s4.isEmpty()) {
			cout << s4.pop() << endl;
		}

		Stack* const s5 = new Stack();
		s5->g(s5);

		while (!s5->isEmpty()) {
			cout << s5->pop() << endl;
		}

		delete s5;
	}

	{
		Stack s6 = i();
		while (!s6.isEmpty()) {
			cout << s6.pop() << endl;
		}
	}

	// Operator Overloading
	{
		Stack s7(10);
		Stack s8(1);

		s7.operator=(s8);

		Stack s9;
		s9 = s9 + 1;
		operator+(s9, 5);

		while (!s9.isEmpty()) {
			cout << s9.pop() << endl;
		}
	}

	return 0;
}
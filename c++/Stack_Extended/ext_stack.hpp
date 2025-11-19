#ifndef EXT_STACK__HPP
#define EXT_STACK__HPP

#include "stack.hpp"

class ExtStack : public Stack {
private:
	int _max;
	bool isFull();

public:
	ExtStack(int size = 10) : Stack(size) { // so kann man den Konstruktor der Überklasse aufrufen
		_max = size;
	};
	void push(int value);
	int pop();
};

#endif // !EXT_STACK__HPP

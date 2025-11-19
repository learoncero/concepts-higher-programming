#include <iostream>
#include "ext_stack.hpp"

bool ExtStack::isFull() {
	return _sp >= _max - 1;
}

void ExtStack::push(int value) {
	std::cout << "ExtStack::push(int value)" << std::endl;
	
	if (!isFull()) {
		Stack::push(value);
	}
}

int ExtStack::pop() {
	std::cout << "ExtStack::pop()" << std::endl;

	return Stack::pop();
}

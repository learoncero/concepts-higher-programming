#include "stack.hpp"

Stack::Stack(int size) {
	_sp = -1;
	_pValues = new int[size];
}

Stack::~Stack() {
	delete[] _pValues;
}

void Stack::push(int value) {
	_sp += 1;
	_pValues[_sp] = value;
}

bool Stack::isEmpty() {
	if (_sp < 0) {
		return true;
	}

	return false;
}

int Stack::pop() {
	int value = _pValues[_sp];
	_sp -= 1;

	return value;
}
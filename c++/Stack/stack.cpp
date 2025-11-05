#include "stack.hpp"

bool Stack:: isFull() {
	return _sp >= _max - 1;
}

Stack::Stack(int capacity) : _max(capacity) {
	pValues = new int[_max];
	_sp = -1;
}

void Stack::push(int value) {
	_sp += 1;
	pValues[_sp] = value;
}

int Stack::pop() {
	int value = pValues[_sp];
	_sp -= 1;

	return value;
}

bool Stack::isEmpty() {
	if (_sp < 0) {
		return true;
	}

	return false;
}
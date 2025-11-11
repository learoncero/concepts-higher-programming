#include "stack.hpp"
#include "stdio.h"
#include <iostream>
using namespace std;

Stack::Stack(int capacity) {
	_max = capacity;
	_pValues = new int[_max];
	_sp = -1;	
}

Stack::Stack(const Stack& s) {
	_max = s._max;
	_sp = s._sp;
	_pValues = new int[_max];

	// copy values
	for (int i = 0; i < _max; i += 1) {
		_pValues[i] = s._pValues[i];
	}
}

Stack& Stack::operator=(const Stack& s) {
	if (this != &s) {
		delete[] _pValues;
		_max = s._max;
		_sp = s._sp;
		_pValues = new int[_max];
		// copy values
		for (int i = 0; i < _max; i += 1) {
			_pValues[i] = s._pValues[i];
		}
	}

	return *this;
}

Stack& operator+(Stack& s, int value) {
	s.push(value);

	return s;
}

Stack& Stack::operator+(int value) {
	push(value);

	return *this;
}

Stack::~Stack() {
	delete[] _pValues;
}

bool Stack::isFull() {
	return _sp >= _max - 1;
}

void Stack::push(int value) {
	if (!isFull()) {
		_sp += 1;
		_pValues[_sp] = value;
	}
}

int Stack::pop() {
	int value = _pValues[_sp];
	_sp -= 1;

	return value;
}

bool Stack::isEmpty() {
	if (_sp < 0) {
		return true;
	}

	return false;
}

void Stack::f(Stack stack) {
	stack.push(10);
}

void Stack::g(Stack* pStack) {
	pStack->push(10);
}

void Stack::h(Stack& stack) {
	stack.push(10);
}

#ifndef STACK__HPP
#define STACK__HPP

class Stack {
private:
	int *pValues;
	int _sp;
	int _max;
	bool isFull();

public:
	Stack(int capacity = 12);
	void push(int value);
	int pop();
	bool isEmpty();
};

#endif // STACK_HPP
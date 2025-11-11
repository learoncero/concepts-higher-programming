#ifndef STACK__HPP
#define STACK__HPP

class Stack {
private:
	int* _pValues;
	int _sp;
	int _max;
	bool isFull();

public: 
	Stack(int capacity = 12); // constructor
	Stack(const Stack& s);
	~Stack(); // destructor
	Stack& operator=(const Stack& s); // assignment operator
	Stack& operator+(int value);
	void push(int value);
	int pop();
	bool isEmpty();
	void f(Stack stack);
	void g(Stack* pStack);
	void h(Stack& stack);
};

Stack& operator+(Stack& s, int value);

#endif // STACK_HPP
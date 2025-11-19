#ifndef STACK__HPP
#define STACK__HPP

class Stack {
protected: // changed from private to protected
	int* _pValues;
	int _sp;


public:
	Stack(int size = 10);
	
	virtual ~Stack();
	
	virtual void push(int value);
	bool isEmpty();
	virtual int pop();
};

#endif // !STACK__HPP

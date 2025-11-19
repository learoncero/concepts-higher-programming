#include <iostream>
#include "stack.hpp"
#include "ext_stack.hpp"
using namespace std;

void clearStack(Stack s) {
	while (!s.isEmpty()) {
		cout << s.pop() << endl;
	}
}

int main() {
	ExtStack s1;
	s1.push(10);
	s1.push(20);

	//clearStack(s1);

	Stack& s2 = s1;
	cout << s2.pop() << endl;

	return 0;
}
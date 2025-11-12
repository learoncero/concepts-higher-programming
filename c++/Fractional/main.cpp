#include "fractional.hpp"
using namespace std;

int main() {
	Fractional f1(1, 2);
	Fractional f2(1, 4);

	Fractional f3;
	f3 = f1 + f2;

	Fractional f4 = f3 + 1.5;

	cout << f3 << endl;
	cout << f4 << endl;

	Fractional f5 = 1.5 + f1;
	Fractional f6 = f1 + 1.5;
	Fractional f7 = 1.5 + 1.5;

	cout << f5 << endl;
	cout << f6 << endl;
	cout << f7 << endl;
}
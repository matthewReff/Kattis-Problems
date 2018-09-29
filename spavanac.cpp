#include <iostream>
using namespace std;

int main() {

	int num1;
	int num2;
	cin >> num1;
	cin >> num2;
	num2 -= 45;
	if (num2 < 0) {
		num1 -= 1;
		num2 += 60;
	}
	if (num1 < 0) {
		num1 = 23;
	}
	cout << num1 << " " << num2;
    return 0;
}


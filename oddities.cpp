#include <iostream>
using namespace std;

int main() {

	int num1;
	int num2;
	cin >> num1;
	for (int i = 0; i < num1; i++) {
		cin >> num2;
		if (abs(num2) % 2 == 0) {
			cout << num2 << " is even\n";
		}
		else {
			cout << num2 << " is odd\n";
		}
	}
    return 0;
}


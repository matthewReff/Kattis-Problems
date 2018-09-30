#include <iostream>
#include <string>
using namespace std;
int main()
{
	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;

	for (int i = 0; i < num3; i++) {

		if (((i + 1) % num1) == 0 || ((i + 1) % num2) == 0) {



			if ((i + 1) % num1 == 0) {
				cout << "Fizz";
			}if ((i + 1) % num2 == 0) {
				cout << "Buzz";
			}
			cout << endl;
		}
		else {
			cout << i+1 << endl;
		}
	}
    return 0;
}


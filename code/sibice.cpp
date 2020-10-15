#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int num1, num2, num3, hyp, num4;
	cin >> num1 >> num2 >> num3;
	hyp = sqrt(pow(num2, 2) + pow(num3, 2));
	for (int i = 0; i < num1; i++) {
		cin >> num4;
		if (num4 <= hyp){
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	}
	
}


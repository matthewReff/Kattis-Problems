#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	int num1;
	int counter = 0;
	int power = 0;
	cin >> num1;
	while (num1 > pow(2, power)){
		power++;
	}
	for (int i = power; i >= 0; i--){
		if ((num1 % int(pow(2,i))) != 0){
			num1 = num1 % int(pow(2, i));
			counter++;
		}

	}
	cout << fixed << setprecision(0) << pow(2, power) << " " << counter;
	return 0;
}
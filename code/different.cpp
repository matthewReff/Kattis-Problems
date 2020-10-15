#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <ctype.h>
#include <unordered_set>
using namespace std;

int main(){
	long long num1;
	long long num2;
	while (cin >> num1 >> num2){
		cout << abs(num1 - num2) << endl;
	}
	return 0;
}
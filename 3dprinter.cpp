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
	int num1;
	int expon;
	cin >> num1;
	expon = ceil(log2(num1));
	cout << expon +1;
	return 0;
}
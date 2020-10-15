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
	string string1;
	string string2;
	cin >> string1 >> string2;
	if (string1.length() < string2.length()){
		cout << "no";
	}
	else{
		cout << "go";
	}
	return 0;
}
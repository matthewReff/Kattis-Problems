#define _USE_MATH_DEFINES
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
	string outString;
	int stringPairs;
	cin >> stringPairs;
	for (int i = 0; i < stringPairs; i++){
		cin >> string1 >> string2;
		for (int j = 0; j < string1.length(); j++){
			if (string1.at(j) == string2.at(j)){
				outString += ".";
			}
			else{
				outString += "*";
			}
		}
		cout << string1 << endl << string2 << endl << outString << endl << endl;
		outString.erase(outString.begin(), outString.end());
	}
	
	return 0;
}
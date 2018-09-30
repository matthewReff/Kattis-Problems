#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main(){
	string inputString;
	string string1;
	string string2;
	string string3;
	string string4;
	string string5;
	int total = 0;
	int rotation = 0;
	cin >> inputString;

	string1 = inputString.substr(0, inputString.length()/2); //divide
	string2 = inputString.substr(inputString.length()/2, inputString.length());

	for (int i = 0; i < string1.length(); i++){ //rotate
		total += string1.at(i) - 'A';
		//cout << string1.at(i) - 'A' << " ";
	}
	for (int i = 0; i < string1.length(); i++){
		string3+= char(97+(((string1.at(i) - 'A')+total)%26));
	}
	total = 0;
	for (int i = 0; i < string2.length(); i++){
		total += string2.at(i) - 'A';
		//cout << string2.at(i) - 'A' << " ";
	}
	for (int i = 0; i < string2.length(); i++){
		string4 += char(97 + (((string2.at(i) - 'A') + total) % 26));
	}
	//cout << string3;
	//cout << string4;
	for (int i = 0; i < string1.length(); i++){
		string5 += char(65+(((string3.at(i) - 'a') + (string4.at(i) - 'a')) % 26));
	}

	
	cout << string5;

	return 0;
}
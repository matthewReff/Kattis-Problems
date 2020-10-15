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
	int cases;
	int dataNum;
	int smaller;
	string tempString;
	vector<int> red;
	vector<int> blue;
	cin >> cases;
	for (int i = 0; i < cases; i++){
		cin >> dataNum;
		int total = 0;
		for (int j = 0; j < dataNum; j++){
			cin >> tempString;
			//cout << tempString << endl;
			//cout << tempString.at(tempString.length() - 1) << endl;
			if (tempString.at(tempString.length() - 1) == 'R'){
				red.push_back(stoi(tempString));
			}
			else if (tempString.at(tempString.length() - 1) == 'B'){
				blue.push_back(stoi(tempString));
			}
		}
		
		//cout << red.size() << endl;
		//cout << blue.size() << endl;
		sort(red.begin(),red.end());
		sort(blue.begin(), blue.end());
		
		
		if (red.size() > blue.size()){
			smaller = blue.size();
		}
		else{
			smaller = red.size();
		}
		if (smaller == 0){
			cout << "Case #" << i + 1 << ": " << total << endl;
			red.erase(red.begin(), red.end());
			blue.erase(blue.begin(), blue.end());
			continue;
		}
		for (int j = 0; j < smaller; j++){
			total += red[red.size() - j - 1] - 1;
			//cout << total << endl;
			total += blue[blue.size() - j -1] - 1;
			//cout << total << endl;
		}
		cout << "Case #" << i + 1 << ": " << total << endl;
		red.erase(red.begin(),red.end());
		blue.erase(blue.begin(),blue.end());
	}
	return 0;
}
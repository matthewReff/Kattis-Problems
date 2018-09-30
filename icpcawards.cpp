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
	vector<string> schools;
	vector<string> teams;
	string school;
	string team;
	int data;
	
	cin >> data;
	for (int i = 0; i < data; i++){
		bool found = false;
		cin >> school;
		cin >> team;
		for (int j = 0; j < schools.size(); j++){
			if (schools[j] == school){
				found = true;
			}
		}
		if (!found && teams.size() < 13){
			schools.push_back(school);
			teams.push_back(team);
		}
	}
	for (int i = 0; i < 12; i++){
		cout << schools[i] << " " << teams[i];
		cout << endl;
	}

	return 0;
}
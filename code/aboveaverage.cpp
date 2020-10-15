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
	int classes;
	int students;
	int score;
	vector<int> scores;
	double avg;
	
	cin >> classes;
	cout << fixed << setprecision(3);
	for (int i = 0; i < classes; i++){
		double total = 0;
		double aboveAvg = 0;
		cin >> students;
		for (int j = 0; j < students; j++){
			cin >> score;
			scores.push_back(score);
			total += score;
		}
		avg = total / students;
		for (int j = 0; j < students; j++){
			if (scores[j] > avg){
				aboveAvg += 1;
			}
		}
		cout << (aboveAvg / students * 100) << "%" << endl;
		scores.erase(scores.begin(),scores.end());
	}
	return 0;
}
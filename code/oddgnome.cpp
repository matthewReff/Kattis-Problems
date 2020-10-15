#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>

using namespace std;

int main() {
	int sets;
	int numInSet;
	int num;
	int min;
	int max;
	int answer;
	int initial;
	int j;
	bool found;
	vector<int> dataSet;
	cin >> sets;
	for (int i = 0; i < sets; i++)
	{
		found = false;
		answer = 0;
		dataSet.clear();
		cin >> numInSet;
		for (int j = 0; j < numInSet; j++)
		{
			cin >> num;
			dataSet.push_back(num);
		}
		initial = dataSet[0];
		j = 1;
		while(j < dataSet.size() -1 && !found)
		{
			if (dataSet[j] != initial + j)
			{
				answer = j+1;
				found = true;
			}
			j++;
		}
		cout << answer << "\n";
	}
	return 0;
}

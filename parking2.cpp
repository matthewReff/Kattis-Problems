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
	vector<int> dataSet;
	cin >> sets;
	for (int i = 0; i < sets; i++)
	{
		dataSet.clear();
		cin >> numInSet;
		for (int j = 0; j < numInSet; j++)
		{
			cin >> num;
			dataSet.push_back(num);
		}
		min = dataSet[0];
		max = dataSet[0];
		for (int j = 1; j < numInSet; j++)
		{
			if (dataSet[j] > max)
			{
				max = dataSet[j];
			}
			if (dataSet[j] < min)
			{
				min = dataSet[j];
			}
		}
		cout << (max - min) * 2 << "\n";
	}
	return 0;
}

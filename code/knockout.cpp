#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

map<int, double> getOpponentProb(const vector<map<int, double>> & chances, int min, int max)
{
	int size = max - min;
	int midPoint = min + (size)/2;
	if(size > 1)
	{
		auto leftSide = getOpponentProb(chances, min, midPoint);
		auto rightSide = getOpponentProb(chances, midPoint, max);

		// Interlace
		map<int, double> newMap;
		for(auto leftMember : leftSide)
		{
			int leftValue = leftMember.first;
			double leftProb = leftMember.second;
			for(auto rightMember : rightSide)
			{
				int rightValue = rightMember.first;
				double rightProb = rightMember.second;
				double total = rightValue + leftValue;
				newMap[rightValue] += rightValue / total * rightProb * leftProb;
				newMap[leftValue] += leftValue / total * rightProb * leftProb;
			}
		}
		return newMap;
	}
	else
	{
		return chances[min];
	}
}

double getSurviveChance(const vector<map<int, double>> & chances, int min, int max, int myValue)
{
	int size = max - min;
	int midPoint = min + (size)/2;

	if(size > 1)
	{
		auto opponentChances = getOpponentProb(chances, min, midPoint);
		auto surviveChance = getSurviveChance(chances, midPoint, max, myValue);

		float newSurviveChance = 0.0;
		for(auto opponent : opponentChances)
		{
			int strength = opponent.first;
			double prob = opponent.second;
			float total = strength + myValue;
			newSurviveChance += myValue / total * prob;
		}

		return newSurviveChance * surviveChance;
	}
	return 1.0;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    int members;
    cin >> members;
    members--;

    int myValue;
    cin >> myValue;

    vector<int> opponents(members);
    for(int i = 0; i < members; i++)
    {
    	cin >> opponents[i];
    }
    sort(opponents.rbegin(), opponents.rend());
    opponents.push_back(myValue);

    members++;
    // Initial round
    int difference = (members) - (1 << int(log2(members)));

    // Resolve our bracket down till we have a clean power of two
    vector<map<int, double>> chances;
    for(int i = 0; i < difference; i++)
    {
    	map<int, double> thisChance;
    	float total = opponents[2 * i] + opponents[2 * i + 1];
    	int A = opponents[2 * i];
    	int B = opponents[2 * i + 1];
    	thisChance[A] += A / float(total);
    	thisChance[B] += B / float(total);
    	chances.push_back(thisChance);
    }

    for(int i = difference * 2; i < members; i++)
    {
    	map<int, double> tempMap;
    	tempMap[opponents[i]] = 1.0;
    	chances.push_back(tempMap);
    }

    /*
    for(auto mapThing : chances)
    {
    	cout << "\n";
    	for(auto entry : mapThing)
    	{
    		cout << entry.first << " " << entry.second;
    	}
    }
    cout << "\n\n";
    */
    // Now we have even maps
    cout << fixed << setprecision(10);
    cout << getSurviveChance(chances, 0, chances.size(), myValue) << "\n";

    return 0;
}

#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;


vector<string> pySplit(string & splitString, char seperator = ' ')
{
	int endIndex = 0;
	vector<string > seperated;
	seperated.push_back("");
	for (int i = 0; i < splitString.size(); i++)
	{
		if (splitString[i] == seperator)
		{
			endIndex++;
			seperated.push_back("");
		}
		else
		{
			seperated[endIndex] += splitString[i];
		}
	}
	return seperated;
}

struct personClass
{
    string classString;
    string name;
    bool operator<(personClass R)
    {
        if(classString == R.classString)
        {
            return name > R.name;
        }
        return classString < R.classString;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll cases;
    ll numPeople;
    string personName, status, garb;
    cin >> cases;
    for(i = 0 ; i < cases; i++)
    {
        cin >> numPeople;
        vector<personClass> people(numPeople);
        for(j = 0; j < numPeople; j++)
        {
            cin >> personName >> status >> garb;
            vector<string> temp = pySplit(status, '-');
            string statusString = "";
            reverse(temp.begin(), temp.end());
            for(k = 0; k < temp.size(); k++)
            {
                switch(temp[k][0])
                {
                    case 'u':
                        statusString += '2';
                        break;
                    case 'm':
                        statusString += '1';
                        break;
                    case 'l':
                        statusString += '0';
                        break;
                };
            }
            if(statusString.size() < 10)
            {
                for(k = statusString.size(); k <= 10; k++)
                {
                    statusString += '1';
                }
            }
            people[j].classString = statusString;
            people[j].name = personName.substr(0,personName.size()-1);
        }
        sort(people.rbegin(), people.rend());
        for(auto thing : people)
        {
            cout << thing.name << "\n";
        }
        cout << "==============================\n";
    }
    
    return 0;
}

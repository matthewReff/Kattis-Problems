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

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll cases;
    ll caseNum;
    ll arrSize;
    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
    	cin >> caseNum >> arrSize;
    	vector<int> original(arrSize, -1);
    	vector<int> second(arrSize);
    	for(int j = 0; j < arrSize; j++)
    	{
    		cin >> original[j];
    		second[j] = original[j];
    	}
    	sort(second.begin(), second.end());

    	int secondIndex = 0;

    	for(int i = 0; i < original.size(); i++)
    	{
			if(original[i] == second[secondIndex])
			{
				secondIndex++;
			}
    	}

    	cout << caseNum << " " << original.size() - secondIndex << "\n";
    }

    return 0;
}

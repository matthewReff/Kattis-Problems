// The proper way to do this is with discret fourier transform(DFT) if I remeber correctly.
// The obvious way is done here is faster, but you can do better
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
    cin >> cases;

    ll deg1, deg2;
    for(int i = 0; i < cases; i++)
    {
    	cin >> deg1;
    	vector<int> poly1(deg1 + 1);
    	for(int j = 0; j < deg1 + 1; j++)
    	{
    		cin >> poly1[j];
    	}

    	cin >> deg2;
    	vector<int> poly2(deg2 + 1);
    	for(int j = 0; j < deg2 + 1; j++)
    	{
    		cin >> poly2[j];
    	}

    	map<int, int> outPoly;

    	for(int j = 0; j < (int)poly1.size(); j++)
    	{
    		for(int k = 0; k < (int)poly2.size(); k++)
    		{
    			outPoly[j+k] += poly1[j] * poly2[k];
    		}
    	}

    	cout << outPoly.size() - 1 << "\n";
    	for(auto elem : outPoly)
    	{
    		cout << elem.second << " ";
    	}
    	cout << "\n";
    }
    return 0;
}

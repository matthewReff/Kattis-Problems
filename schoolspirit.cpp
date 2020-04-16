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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll students;
    vector<ll> scores;

    cin >> students;
    ll score;
    for(i = 0; i < students; i++)
    {
    	cin >> score;
    	scores.push_back(score);
    }

    sort(scores.rbegin(), scores.rend());

    double initialVal = 0;

    for(i = 0; i < students; i++)
    {
    	initialVal += scores[i] * pow(4/5.0, i);
    }

    initialVal /= 5.0;

    double avg = 0;
    for(i = 0;  i < students; i++)
    {
    	double thisTot = 0;
    	ll used = 0;
    	for(j = 0; j < students; j++)
    	{
    		if(i != j)
    		{
	    		thisTot += scores[j] * pow(4/5.0, used);
	    		used++;
	    	}
    	}
    	//cout << thisTot << "\n";
    	thisTot /= 5.0;
    	avg += thisTot;
    }
    avg /= students;

    cout << fixed << setprecision(10);
    cout << initialVal << "\n";
    cout << avg << "\n";
    return 0;
}

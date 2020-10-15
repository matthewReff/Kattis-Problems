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
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ll p, d;

    cin >> d >> p; 	
    vector<pair<ll, ll>> votes(p, make_pair(0, 0));


    ll pres, voteA, voteB;
    ll totalVotes = 0;
    ll totalwastedA = 0;
    ll totalwastedB = 0;
    for(int i = 0; i < d; i++)
    {
    	cin >> pres >> voteA >> voteB;
    	votes[pres-1].first += voteA;
    	votes[pres-1].second += voteB;
    	totalVotes += voteA;
    	totalVotes += voteB;
    }

    for(i = 0; i < p; i++)
    {
    	ll wastedA;
    	ll wastedB;
    	if(votes[i].first > votes[i].second)
    	{
    		cout << "A ";
    		wastedA = votes[i].first - floor(double(votes[i].first + votes[i].second) + 1)/2 ;
    		wastedB = votes[i].second;
    	}
    	else
    	{
    		cout << "B ";
    		wastedA = votes[i].first;
    		wastedB = votes[i].second - floor(double(votes[i].first + votes[i].second) + 1)/2;
    	}
   		cout << wastedA << " " << wastedB << "\n";
   		totalwastedB += wastedB;
   		totalwastedA += wastedA;
    }
    cout << fixed << setprecision(10);
    cout << double(abs(totalwastedA - totalwastedB)) / totalVotes << "\n";
    return 0;
}
 	
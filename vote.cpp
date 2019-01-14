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



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    ll cases;
    ll canadates;
    ll totalVotes;
    ll maxVotesSoFar;
    
    
    cin >> cases;
    for(i = 0; i < cases; i++)
    {
        cin >> canadates;
        vector<ll> votesForCanadates(canadates);
        ll maxVotesSoFar = 0;
        ll totalVotes = 0;
        ll highestCanadate = -1;
        bool tie = false;
        for(j = 0; j < canadates; j++)
        {
            cin >> votesForCanadates[j];
            totalVotes += votesForCanadates[j];
            if(votesForCanadates[j] == maxVotesSoFar)
            {
                tie = true;
            }
            if (votesForCanadates[j] > maxVotesSoFar)
            {
                maxVotesSoFar = votesForCanadates[j];
                highestCanadate = j;
                tie = false;
            }
           
        }
        if (tie)
        {
            cout << "no winner\n";   
        }
        else if ((double)maxVotesSoFar / totalVotes > .5)
        {
            cout << "majority winner " << highestCanadate + 1 << "\n";
        }
        else
        {
            cout << "minority winner " << highestCanadate + 1 << "\n";
        }
       
    } 
    return 0;
}

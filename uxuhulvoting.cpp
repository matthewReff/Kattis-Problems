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

vector<ll> optimize(vector<ll> voterPrefs, vector<ll> willVoteFor, map<ll, vector<ll>> possibleVotes)
{
    ll bestChoice = -1;
    ll indexOfBestChoice = 0;
    vector<ll> newWillVoteFor(8);
    
    for(ll j = 0; j < 8; j++)
    {
        bestChoice = -1;
        indexOfBestChoice = 0;
        for(auto possibility : possibleVotes[j])
        {
            if(voterPrefs[willVoteFor[possibility]] > bestChoice)
            {
                bestChoice = voterPrefs[willVoteFor[possibility]];
                indexOfBestChoice = possibility;
            }
        }
        newWillVoteFor[j] = willVoteFor[indexOfBestChoice];
    }
    return newWillVoteFor;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll cases;
    ll numPriests;
    ll prefNum;
    map<ll, string> stoneStates;
    map<ll, vector<ll>> possibleVotes;
    vector<ll> willVoteFor(8, -1);
    stoneStates[0] = "NNN";
    stoneStates[1] = "NNY"; 
    stoneStates[2] = "NYN"; 
    stoneStates[3] = "NYY"; 
    stoneStates[4] = "YNN"; 
    stoneStates[5] = "YNY"; 
    stoneStates[6] = "YYN"; 
    stoneStates[7] = "YYY";
    
    possibleVotes[0] = {1, 2, 4};
    possibleVotes[1] = {0, 3, 5};
    possibleVotes[2] = {0, 3, 6};
    possibleVotes[3] = {1, 2, 7};
    possibleVotes[4] = {0, 5, 6};
    possibleVotes[5] = {1, 4, 7}; 
    possibleVotes[6] = {2, 4, 7};
    possibleVotes[7] = {3, 5, 6};  
        
    cin >> cases;
    for(i = 0; i < cases; i++)
    {
        cin >> numPriests;
        vector<vector<ll>> voterPrefs(numPriests);
        for(j = 0; j < numPriests; j++)
        {
            voterPrefs[j].resize(8);
            for(k = 0; k < 8; k++)
            {
                cin >> prefNum;
                voterPrefs[j][k] =  8 - prefNum;
            }
        }
        
        //do bottom case to make function more simple
        ll bestChoice = -1;
        ll indexOfBestChoice = 0;
        for(j = 0; j < 8; j++)
        {
            bestChoice = -1;
            indexOfBestChoice = 0;
            for(auto possibility : possibleVotes[j])
            {
                if(voterPrefs[numPriests-1][possibility] > bestChoice)
                {
                    bestChoice = voterPrefs[numPriests-1][possibility];
                    indexOfBestChoice = possibility;
                }
            }
            willVoteFor[j] = indexOfBestChoice;
        }
        for(j = numPriests - 2; j >= 0; j--)
        { 
            
            willVoteFor = optimize(voterPrefs[j], willVoteFor, possibleVotes);

        }
        cout << stoneStates[willVoteFor[0]] << "\n";
        
    }
    return 0;
}

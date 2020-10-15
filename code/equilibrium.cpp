#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <map>

typedef long long ll;
using namespace std;

int main()
{

    ll i, j, k;
   
    ll cases;
    ll nodes; 
    ll topFreq;
    ll numFreq;
    vector<string> parse;
    string numString = "";
    map<ll, ll> frequencies;
    ll depth = 0;
    int temp, d = 0;


    cin >> cases;
    parse.resize(cases);
    for (i = 0; i < cases; i++)
    {
        frequencies.clear();
        cin >> parse[i];
        d = 0;
        nodes = 0;
        numFreq = 0;
        for (j = 0; j < parse[i].size(); j++)
        {
            if (isdigit(parse[i][j]))
            {
                numString += parse[i][j];
            }
            else if( numString != "" )
            {
                temp = stoi(numString);
                frequencies[temp * pow(2, d)]++;
                nodes++;
                numString = "";
            }
            if (parse[i][j] == '[')
            {
                d++;
            }
            if (parse[i][j] == ']')
            {
                d--;
            }
        }
        if (!numString.empty())
        {
            temp = stoi(numString);
            frequencies[temp * pow(2, d)]++;
            nodes++;
            numString = "";
        }
        map<ll, ll>::iterator itr;
        for (itr = frequencies.begin(); itr != frequencies.end(); itr++)
        {
            if (itr->second > numFreq)
            {
                numFreq = itr->second;
                topFreq = itr->first;
            }
        }
        cout << nodes - numFreq << "\n";
    }


    return 0;
}
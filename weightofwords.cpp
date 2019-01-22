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
    
    ll letters, weight;
    string outputString;
    ld avgLetter;
    cin >> letters >> weight;
    ll numLetters = letters;
    ll currentWeight = 0;
    
    if(weight < letters || weight > 26*letters)
    {
        cout << "impossible\n";
    }
    else
    {
        avgLetter = weight / (ld)letters;
        //cout << avgLetter << "\n";
        while(numLetters--)
        {
            //cout << "expected weight: " << avgLetter * (letters - numLetters) << "\n";
            //cout << "current weight: " << currentWeight  + (int)avgLetter<< "\n";
            if(avgLetter * (letters - numLetters) <= currentWeight + (int)avgLetter)
            {
                outputString += char(avgLetter + 'a' - 1);
                currentWeight += avgLetter;
                //cout << char(avgLetter + 'a') << "\n";
            }
            else
            {
                outputString += char(avgLetter + 'a');
                currentWeight += avgLetter + 1;
                //cout << char(avgLetter + 'a' + 1) << "\n";
            }
            
        }
        cout << outputString << "\n";
    }
    
    return 0;
}

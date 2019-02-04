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
    
    char letter;
    deque<char> word;
    string finishedWord = "";
    while(cin >> letter)
    {
        if(letter != '<')
        {
            word.push_front(letter);
        }
        else
        {
            word.pop_front();
        }
    }
    
    while(word.size())
    {
        finishedWord.push_back(word.front());
        word.pop_front();
    }
    
    reverse(finishedWord.begin(), finishedWord.end());
    cout << finishedWord << "\n";
    return 0;
}

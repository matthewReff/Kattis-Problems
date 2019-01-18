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
    
    ll time;
    ll dayNum = 1;
    string command, person;
    map<string, int> enteredRecord;
    map<string, ll> moneyOwed;
    
    cout << fixed << setprecision(2);
    while(cin >> command)
    {
        if(command == "CLOSE")
        {
            cout << "Day " << dayNum << "\n";
            for(auto entry : moneyOwed)
            {
                cout << entry.first << " $" << entry.second / (double)10 << "\n";
            }
            cout << "\n";
            moneyOwed.clear();
            dayNum++;
        }
        else if (command != "OPEN")
        {
            cin >> person >> time;
            if(command == "ENTER")
            {
                enteredRecord[person] = time;
            }
            else
            {
                moneyOwed[person] += time - enteredRecord[person];
            }
        }
    }
    return 0;
}



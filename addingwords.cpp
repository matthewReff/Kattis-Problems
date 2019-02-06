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
    
    map<string, ll> vars;
    map<ll, string> backVars;
    string command;
    string currentVar;
    ll currentVal;
    bool valid = true;
    char op;
    
    while(cin >> command)
    {
        if(command == "def")
        {
            cin >> currentVar >> currentVal;
            map<string, ll>::iterator itr1 = vars.find(currentVar);
            map<ll, string>::iterator itr2 = backVars.find(currentVal);
            if(itr1 != vars.end())
            {
                backVars.erase(itr1->second);
                vars.erase(itr1);
            }
            if(itr2 != backVars.end())
            {
                backVars.erase(itr2);
            }
            vars[currentVar] = currentVal;
            backVars[currentVal] = currentVar;
        }
        else if(command == "calc")
        {
            string outputThings;
            cin >> currentVar;
            outputThings += currentVar;
            outputThings += ' ';
            valid = true;
            if(vars.find(currentVar) != vars.end())
            {
                currentVal = vars[currentVar];
            }
            else
            {
                valid = false;   
            }
            while(cin >> op && op != '=')
            {
                cin >> currentVar;
                outputThings += op;
                outputThings += ' ';
                outputThings += currentVar;
                outputThings += ' ';
                if(vars.find(currentVar) == vars.end())
                {
                    valid = false;
                }
                else if(valid)
                {
                    if(op == '-')
                    {
                        currentVal -= vars[currentVar];
                    }
                    else
                    {
                        currentVal += vars[currentVar];
                    }                        
                }
            }
            outputThings += "= ";
            cout << outputThings;
            if(valid && backVars.find(currentVal) != backVars.end())
            {
                cout << backVars[currentVal] << "\n";
            }
            else
            {
                cout << "unknown\n";
            }
        }
        else
        {
            vars.clear();
            backVars.clear();
        }
    }
    return 0;
}

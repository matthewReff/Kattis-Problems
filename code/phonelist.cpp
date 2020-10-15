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

typedef long long ll;
using namespace std;

int main()
{

    ll i, j, k;
    vector<string> myList;
    string temp;
    ll cases;
    ll numbers;
    ll myMin;
    bool found = false;

    cin >> cases;
    for (i = 0; i < cases; i++)
    {
        myList.clear();
        found = false;
        cin >> numbers;
        for (j = 0; j < numbers; j++)
        {
            cin >> temp;
            myList.push_back(temp);
        }
        sort(myList.begin(), myList.end());
        for (j = 0; j < myList.size() - 1; j++)
        {
            myMin = min(myList[j].size(), myList[j + 1].size());
            if (myList[j].substr(0, myMin) == myList[j + 1].substr(0, myMin))
            {
                found = true;
            }
        }
        if (found)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

    return 0;
}
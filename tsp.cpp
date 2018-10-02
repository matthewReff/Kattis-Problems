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
    double garb;

    cin >> cases;
    pair <double, int> temp;
    vector<pair<double, int>> bodge;

    for (i = 0; i < cases; i++)
    {
        cin >> garb;
        temp.first = garb;
        temp.second = i;
        cin >> garb;
        bodge.push_back(temp);
    }
    sort(bodge.begin(), bodge.end());

    for (i = 0; i < cases; i++)
    {
        cout << bodge[i].second << "\n";
    }
}


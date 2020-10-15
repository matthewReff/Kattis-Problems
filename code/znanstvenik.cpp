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

    int r, c;
    cin >> r >> c;

    // input string
    vector<string> v(r);
    for (int i = 0; i < r; i++)
        cin >> v[i];

    // transpose
    vector<string> trans(c, "");
    for (int i = 0; i < c; i++) {
        for (int j = r-1; j >=0; j--) {
            trans[i].push_back(v[j][i]);
        }
    }

    sort(trans.begin(), trans.end());
    int count, countMax = -1;
    for (int i = 0; i < c - 1; i++) {
        for (count = 0; count < r; count++) {
            if (trans[i][count] != trans[i + 1][count])
                break;
        }
        countMax = max(count, countMax);
    }

    cout << trans[0].length() - countMax - 1 << endl;

  
    return 0;

}


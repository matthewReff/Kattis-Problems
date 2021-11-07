#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <list>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string inputString;
    cin >> inputString;

    // A linked list allows for us to naively implement moving left/right or deleting in place
    // with very good time complexity
    list<char> password;
    list<char>::iterator cursor = password.begin();

    for(int i = 0; i < (int)inputString.size(); i++) {
    	char entry = inputString[i];

    	if(entry == 'L') {
    		cursor--;
    	}
    	else if(entry == 'R') {
    		cursor++;
    	}
    	else if(entry == 'B') {
    		cursor--;
    		cursor = password.erase(cursor);
    	}
    	else {
    		password.insert(cursor, entry);
    	}
    }

    for(auto entry : password) {
    	cout << entry;
    }
    cout << "\n";
    return 0;
}

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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll hintLen, fullKeyLen;
    string hint;
    string text;

    cin >> hintLen >> fullKeyLen;
    cin >> hint;
    cin >> text;


    reverse(hint.begin(), hint.end());
    reverse(text.begin(), text.end());

    string plain = hint;

    for(i = 0; i < fullKeyLen - hintLen; i++)
    {
    	char plainChar = plain[i];
    	char ciphChar = text[i];
    	//cout << "plain: " << plainChar << "\n";
    	//cout << "cipher: " << ciphChar << "\n";
    	if (plainChar <= ciphChar)
    	{
    		plain += char(ciphChar - plainChar + 'a');
    		//cout << ciphChar - plainChar + 'a' << "\n";
    	}
    	else
    	{
    		plain += char('z' + ciphChar - plainChar +1);
    		//cout << 'z' - plainChar + 'a' << "\n";
    	}
    }

    reverse(plain.begin(), plain.end());

    cout << plain << "\n";	
    return 0;
}

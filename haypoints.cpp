#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main()
{
    ll i, j, k;
    ll words;
    ll cases;
    string word;
    string line;
    
    ll amount;
    map <string, int> wordDict;
    map <string, int>::iterator itr;
    vector<string> wordVec;
    
    cin >> words >> cases;
    
    for(i = 0; i < words; i++)
    {
        cin >> word >> amount;
        wordDict[word] = amount;
    }
    
    for(i = 0; i < cases; i++)
    {
       
        ll total = 0;
        while(cin >> line && line != ".")
        {
            itr = wordDict.find(line);
            if (itr != wordDict.end())
            {
                total += wordDict[line];
            }  
        }
        cout << total << "\n";    
    }
    return 0;
}

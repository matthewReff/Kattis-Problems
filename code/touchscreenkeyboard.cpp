#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main()
{
	vector<char> keyBoard = 
	{'q','w','e','r','t','y','u','i','o','p', 
	'a','s','d','f','g','h','j','k','l','0',
	'z','x','c','v','b','n','m','0','0','0'};
	struct myPair{
	    int diff;
	    string compString;
	    bool operator < (myPair & cmp)
	    {   
	        if(diff == cmp.diff)
	        {
	            return compString < cmp.compString;
	        }
	        else
	        {
	            return diff < cmp.diff;
	        }
	    }
	};
	ll cases, i, j, k;
	ll distance = 0;
	ll index1, index2;
	string compString;
	ll numStrings;
	vector<string> compares;
	vector<myPair> outString;
    
    cin >> cases;
    
    for(i = 0; i < cases; i++)
    {
        myPair temp;
        compares.clear();
        outString.clear();
        cin >> compString >> numStrings;
        compares.resize(numStrings);
        for(j = 0; j < numStrings; j++)
        {
            distance = 0;
            cin >> compares[j];
            for(k = 0; k < compares[j].size();k++)
            {
                index1 = 0;
                index2 = 0;
                while(keyBoard[index1] != compString[k])
                {
                    index1++;
                }
                while(keyBoard[index2] != compares[j][k])
                {
                    index2++;
                }
                //cout << index1 << " " << index2 << " ";
                distance+= abs(index1/10 - index2/10);
                distance+= abs(index1%10 - index2%10);
            }
            temp.diff = distance;
            temp.compString = compares[j];
            outString.push_back(temp);
        }
        sort(outString.begin(), outString.end());
        for(j = 0; j < outString.size(); j++)
        {
            cout << outString[j].compString << " " << outString[j].diff << "\n";
        }
        
    }	
	return 0;
}

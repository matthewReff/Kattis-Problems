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
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    
    ll r, c;
    ll hopperRow, hopperCol;
  	ll leafRow, leafCol;

  	while(cin >> r >> c >> hopperRow >> hopperCol >> leafRow >> leafCol)
  	{
  		vector<vector<ll>> adj(101*101+1);
  		vector<bool> seen(101*101+1, false);
  		vector<int> distance(101*101+1, 0);

  		for(i = 0; i < r; i++)
  		{
  			for(j = 0; j < c; j++)
  			{
  			
  				for(k = 0; k < 8; k++)
  				{
  						ll tempRow = i;
  				ll tempCol = j;
  					switch(k)
  					{
  						case 0:
  							{
  								tempCol += 2;
  								tempRow += 1;
  								break;
  							}
  							case 1:
  							{
  								tempCol += 2;
  								tempRow -= 1;
  								break;
  							}
  							case 2:
  							{
  								tempCol -= 2;
  								tempRow += 1;
  								break;
  							}
  							case 3:
  							{
  								tempCol -= 2;
  								tempRow -= 1;
  								break;
  							}
  							case 4:
  							{
  								tempCol += 1;
  								tempRow += 2;
  								break;
  							}
  							case 5:
  							{
  								tempCol += 1;
  								tempRow -= 2;
  								break;
  							}
  							case 6:
  							{
  								tempCol -= 1;
  								tempRow += 2;
  								break;
  							}
  							case 7:
  							{
  								tempCol -= 1;
  								tempRow -= 2;
  								break;
  							}
  						}
  						if(tempRow >= 0 && tempRow < r && tempCol >= 0 && tempCol < c)
  						{
  							adj[(tempRow+1)*c + tempCol + 1].push_back((i+1)*c + j + 1);
  						}
  					} //k
  				} //j
  			} //i
  		
  		//for(auto thing : adj)
  		//{
  		//	for(auto subPair : thing.second)
  		//	{
  		//		cout << thing.first.first << " " << thing.first.second << ": " << subPair.first << " " << subPair.second << "\n";
  		//	}
  		//}
  		queue<ll> q;
  		q.push(hopperRow*c +  hopperCol);
  		seen[hopperRow*c + hopperCol] = true;
  		distance[hopperRow*c + hopperCol] = 0;
  		while(q.size())
  		{
  			ll top = q.front();
  			q.pop();
  			for(ll edge : adj[top])
  			{
  				if(!seen[edge])
  				{
					q.push(edge);
					seen[edge] = true;
					distance[edge] = distance[top]+1;
				}
  			}
  		}
  		if(seen[leafRow*c +leafCol])
  		{
  			cout << distance[leafRow*c + leafCol] << "\n";
  		}
  		else 	
  		{
  			cout << "impossible\n";
  		}
  	}
    return 0;
}













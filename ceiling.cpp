//Solved by https://open.kattis.com/users/keshav-manghat

#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int _v)
	{
		this->val = _v;
		this->left = nullptr;
		this->right = nullptr;
	}
	
};

bool isSame(TreeNode* a, TreeNode* b)
{
	if(a == nullptr && b == nullptr) return true;
	if(a == nullptr || b == nullptr)return false;
	return (isSame(a->left,b->left) && isSame(a->right,b->right));
}

int main()
{
	int n;
	cin >> n;
	vector<TreeNode*> v;
	int k;
	cin >> k;
	while(n --> 0)
	{
		int num;
		TreeNode* root;
		for(int i = 0; i < k; i++)
		{
			cin >> num;
			if(i == 0)
			{
				root = new TreeNode(num);
			}
			else
			{
				TreeNode* curr = root;
				while(curr != nullptr)
				{
					if(curr-> val < num)
					{
						if(curr->left == nullptr) 
						{
							curr->left = new TreeNode(num);
							break;
						}
						curr = curr->left;
					}
					else 
					{
						if(curr->right == nullptr) 
						{
							curr->right = new TreeNode(num);
							break;
						}
						curr = curr->right;
					}
				}
			}
		}
		bool found = false;
		for(int i = 0; i < v.size(); i++)
		{
			if(isSame(root,v[i]))
			{
				found = true;
				break;
			}
		}
		
		if(!found)v.push_back(root);
	}
	
	cout << v.size() << endl;
	
	return 0;
}

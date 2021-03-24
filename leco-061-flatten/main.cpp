#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right)
	    : val(x), left(left), right(right)
	{
	}
};
class Solution {
    public:
	void flatten(TreeNode* root)
	{
		if (!root) return;
		flatten(root->left);
		auto right = root->right;
		root->right = root->left;
		root->left = nullptr;
		while (root->right) {
			root = root->right;
		}
		flatten(right);
		root->right = right;
	}
};
int main(int argc, char *argv[])
{
	auto r22 = new TreeNode(6);
	auto r2 = new TreeNode(4);
	auto l2 = new TreeNode(3);
	auto l1 = new TreeNode(2,l2,r2);
	auto r1 = new TreeNode(5,nullptr,r22);
	auto root = new TreeNode(1,l1,r1);
	Solution sol;
	sol.flatten(root);
	auto l = new TreeNode(0,nullptr,root);
	cout<<"ans is:";
	while(l->right){
		cout<<(l->right)->val<<" ";
		l = l->right;
	}

	return 0;
}


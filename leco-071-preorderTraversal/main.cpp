#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right)
	    : val(x), left(left), right(right){}
};
class Solution {
    public:
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> res;
		if (root == nullptr) {
			return res;
		}

		TreeNode *p1 = root, *p2 = nullptr;

		while (p1 != nullptr) {
			p2 = p1->left;
			if (p2 != nullptr) {
				while (p2->right != nullptr &&
				       p2->right != p1) {
					p2 = p2->right;
				}
				if (p2->right == nullptr) {
					res.emplace_back(p1->val);
					p2->right = p1;
					p1 = p1->left;
					continue;
				}
				else {
					p2->right = nullptr;
				}
			}
			else {
				res.emplace_back(p1->val);
			}
			p1 = p1->right;
		}
		return res;
	}
};
int main(int argc, char *argv[])
{
	auto l2 = new TreeNode(3);
	auto r1 = new TreeNode(2,l2,nullptr);
	auto root = new TreeNode(1,nullptr,r1);
	Solution sol;
	auto ans = sol.preorderTraversal(root);
	cout<<"ans is:";
	for(int i = 0;i < ans.size();++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}

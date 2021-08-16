#include <iostream>
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
	int kth = 0;
	int kthSmallest(TreeNode *root, int k)
	{
		if (root == nullptr) return 0;
		int leftRes = kthSmallest(root->left, k);
		if (leftRes != 0) return leftRes;
		kth++;
		if (kth == k) return root->val;
		return kthSmallest(root->right, k);
	}
};
int main(int argc, char *argv[])
{
	auto r2 = new TreeNode(2);
	auto r1 = new TreeNode(1,nullptr,r2);
	auto r4 = new TreeNode(4);
	auto root = new TreeNode(3,r1,r4);
	Solution sol;
	cout<<"ans is:"<<sol.kthSmallest(root,2)<<endl;
	return 0;
}

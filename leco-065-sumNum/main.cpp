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
    int dfs(TreeNode* root, int prevSum) {
        if (root == nullptr) {
            return 0;
        }
        int sum = prevSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        } else {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
int main(int argc, char *argv[])
{
	auto l2 = new TreeNode(5);
	auto r2 = new TreeNode(1);
	auto l1 = new TreeNode(9,l2,r2);
	auto r1 = new TreeNode(0);
	auto root = new TreeNode(4,l1,r1);
	Solution sol;
	auto ans = sol.sumNumbers(root);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

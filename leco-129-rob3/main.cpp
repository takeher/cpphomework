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
struct SubtreeStatus {
	int selected;
	int notSelected;
};

class Solution {
    public:
	SubtreeStatus dfs(TreeNode *node)
	{
		if (!node) {
			return {0, 0};
		}
		auto l = dfs(node->left);
		auto r = dfs(node->right);
		int selected = node->val + l.notSelected + r.notSelected;
		int notSelected = max(l.selected, l.notSelected) +
				  max(r.selected, r.notSelected);
		return {selected, notSelected};
	}

	int rob(TreeNode *root)
	{
		auto rootStatus = dfs(root);
		return max(rootStatus.selected, rootStatus.notSelected);
	}
};
int main(int argc, char *argv[])
{
	auto r22 = new TreeNode(1);
	auto r21 = new TreeNode(3);
	auto r11 = new TreeNode(2, nullptr, r21);
	auto r12 = new TreeNode(3, nullptr, r22);
	auto node = new TreeNode(3, r11, r12);
	Solution sol;
	cout << "ans is:" << sol.rob(node) << endl;
	return 0;
}

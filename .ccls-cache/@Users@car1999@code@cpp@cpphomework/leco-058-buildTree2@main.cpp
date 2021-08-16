#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right)
	    : val(x), left(left), right(right)
	{
	}
};
class Solution {
	int post_idx;
	unordered_map<int, int> idx_map;

    public:
	TreeNode* helper(int in_left, int in_right, vector<int>& inorder,
			 vector<int>& postorder)
	{
		// 如果这里没有节点构造二叉树了，就结束
		if (in_left > in_right) {
			return nullptr;
		}

		// 选择 post_idx 位置的元素作为当前子树根节点
		int root_val = postorder[post_idx];
		TreeNode* root = new TreeNode(root_val);

		// 根据 root 所在位置分成左右两棵子树
		int index = idx_map[root_val];

		// 下标减一
		post_idx--;
		// 构造右子树
		root->right = helper(index + 1, in_right, inorder, postorder);
		// 构造左子树
		root->left = helper(in_left, index - 1, inorder, postorder);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		// 从后序遍历的最后一个元素开始
		post_idx = (int)postorder.size() - 1;

		// 建立（元素，下标）键值对的哈希表
		int idx = 0;
		for (auto& val : inorder) {
			idx_map[val] = idx++;
		}
		return helper(0, (int)inorder.size() - 1, inorder, postorder);
	}
};
class Search {
    public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> ret;
		if (!root) {
			return ret;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int currentLevelSize = q.size();
			ret.push_back(vector<int>());
			for (int i = 1; i <= currentLevelSize; ++i) {
				auto node = q.front();
				q.pop();
				ret.back().push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}

		return ret;
	}
};
int main(int argc, char* argv[])
{
	/*
	 * 中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
*/
	vector<int> inorder{9, 3, 15, 20, 7};
	vector<int> postorder{9, 15, 7, 20, 3};
	Solution sol;
	auto ans = sol.buildTree(inorder, postorder);
	Search s;
	auto anss = s.levelOrder(ans);
	for (int i = 0; i < anss.size(); ++i) {
		for (int j = 0; j < anss[i].size(); ++j) {
			cout << anss[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

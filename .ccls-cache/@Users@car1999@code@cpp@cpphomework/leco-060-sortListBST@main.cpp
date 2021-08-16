#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
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
    public:
	int getLength(ListNode* head)
	{
		int ret = 0;
		for (; head != nullptr; ++ret, head = head->next)
			;
		return ret;
	}

	TreeNode* buildTree(ListNode*& head, int left, int right)
	{
		if (left > right) {
			return nullptr;
		}
		int mid = (left + right + 1) / 2;
		TreeNode* root = new TreeNode();
		root->left = buildTree(head, left, mid - 1);
		root->val = head->val;
		head = head->next;
		root->right = buildTree(head, mid + 1, right);
		return root;
	}

	TreeNode* sortedListToBST(ListNode* head)
	{
		int length = getLength(head);
		return buildTree(head, 0, length - 1);
	}
};
class level {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) {
            return ret;
        }
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return ret;
    }
};
int main(int argc, char *argv[])
{
	auto l4 = new ListNode(9);
	auto l3 = new ListNode(5,l4);
	auto l2 = new ListNode(0,l3);
	auto l1 = new ListNode(-3,l2);
	auto head = new ListNode(-10,l1);
	Solution sol;
	auto ans = sol.sortedListToBST(head);
	level s;
	auto anss = s.levelOrder(ans);
	cout<<"ans is:"<<endl;
	for(int i = 0;i < anss.size();++i){
		for(int j = 0;j < anss[i].size();++j){
			cout<<anss[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

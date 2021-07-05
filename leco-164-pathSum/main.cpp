#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    unordered_map<int, int> mp;
    int DFS(TreeNode* cur, int target, int sum)
    {
        if (cur == nullptr) return 0;
        sum += cur->val;
        ++mp[sum];
        int left = DFS(cur->left, target, sum);
        int right = DFS(cur->right, target, sum);
        --mp[sum];
        int now = mp[sum - target];
        return left + right + now;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        return DFS(root, targetSum, 0);
    }
};
int main(int argc, char *argv[])
{
	auto r0 = new TreeNode(10);	
	auto r1 = new TreeNode(5);	
	auto r2 = new TreeNode(-3);
	r0->left = r1;
	r0->right = r2;
	auto r3 = new TreeNode(3);	
	auto r4 = new TreeNode(2);	
	auto r5 = new TreeNode(11);
	r1->left = r3;
	r1->right = r4;
	r2->right = r5;
	auto r6 = new TreeNode(3);	
	auto r7 = new TreeNode(-2);	
	auto r8 = new TreeNode(1);	
	r3->left = r6;
	r3->right = r7;
	r4->right = r8;
	Solution sol;
	cout<<"ans is:"<<sol.pathSum(r0, 8)<<endl;
	return 0;
}

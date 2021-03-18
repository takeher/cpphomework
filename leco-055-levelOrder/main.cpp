#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector<int>());
            for (int i = 0; i < currentLevelSize; ++i) {
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
int main(int argc, char *argv[])
{
	auto t1 = new TreeNode(3);
	auto t2 = new TreeNode(2);
	auto root = new TreeNode(1,t1,t2);
	Solution sol;
	auto ans = sol.levelOrder(root);
	for(int i = 0;i < ans.size();++i){
		for(int j = 0;j < ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

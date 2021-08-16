#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int last, vector<int>& nums) {
        if (cur == nums.size()) {
            if (temp.size() >= 2) {
                ans.push_back(temp);
            }
            return;
        }
        if (nums[cur] >= last) {
            temp.push_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            temp.pop_back();
        }
        if (nums[cur] != last) {
            dfs(cur + 1, last, nums);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, INT_MIN, nums);
        return ans;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums {4,6,7,7};
	Solution sol;
	auto ans = sol.findSubsequences(nums);
	cout<<"ans is:"<<endl;
	for(int i = 0;i < ans.size();++i){
		for(int j = 0;j < ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

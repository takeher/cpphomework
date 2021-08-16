#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};
int main(int argc, char *argv[])
{
	vector<int> candidates{2,3,6,7};
	int target = 7;
	Solution sol;
	auto ans = sol.combinationSum(candidates, target);
	for (int i = 0;i < ans.size();++i){
		cout<<"[";
		for(int j = 0;j<ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}
	return 0;
}
/* 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> now;
        int sum = 0, n = size(candidates);
        function<void(int)> dfs = [&] (int back) {
            if (sum == target) {
                ret.emplace_back(begin(now), end(now));
            } else if (sum > target) return;
            else {
                for (int i = back; i != n; ++i) {
                    now.push_back(candidates[i]);
                    sum += candidates[i];
                    dfs(i);
                    sum -= candidates[i];
                    now.pop_back();
                }
            }
        };
        dfs(0);
        return ret;
    }
};
 */

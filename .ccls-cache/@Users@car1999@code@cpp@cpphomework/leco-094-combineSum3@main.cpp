#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k, int sum) {
        if (temp.size() + (n - cur + 1) < k || temp.size() > k) {
            return;
        }
        if (temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(cur);
        dfs(cur + 1, n, k, sum);
        temp.pop_back();
        dfs(cur + 1, n, k, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, 9, k, n);
        return ans;
    }
};
int main(int argc, char *argv[])
{
	int k = 3;
	int n = 7;
	Solution sol;
	auto ans = sol.combinationSum3(k, n);
	cout<<"ans is:"<<endl;
	for(int i = 0;i<ans.size();++i){
		for(int j = 0;j<ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

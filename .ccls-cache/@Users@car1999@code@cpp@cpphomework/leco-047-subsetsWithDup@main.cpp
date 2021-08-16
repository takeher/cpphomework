#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
  vector<vector<int>> all_subsets;
  vector<int> subset;
  void subsetsWithDupHelper(vector<int> &nums, int startIndex) {
    all_subsets.push_back(subset);

    unordered_set<int> visited;
    for (int i = startIndex; i < nums.size(); ++i) {
      if (visited.count(nums[i]) == 0) {
        visited.insert(nums[i]);
        subset.push_back(nums[i]);
        subsetsWithDupHelper(nums, i + 1);
      } else {
        continue;
      }
      subset.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    subsetsWithDupHelper(nums, 0);
    return all_subsets;
  }
};
int main(int argc, char *argv[])
{
	vector<int> nums{1,2,2};
	Solution sol;
	vector<vector<int>> ans = sol.subsetsWithDup(nums);
	cout<<"ans is:";
	for(int i = 0;i < ans.size();++i){
		for(int j = 0;j < ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

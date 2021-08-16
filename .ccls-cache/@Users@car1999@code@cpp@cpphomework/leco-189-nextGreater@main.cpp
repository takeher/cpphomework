#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums {1,2,1};
	Solution sol;
	auto ans = sol.nextGreaterElements(nums);
	cout<<"ans is:";
	for(int i = 0;i < ans.size();++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}

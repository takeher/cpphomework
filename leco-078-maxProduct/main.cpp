#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums {2,3,-1,4};
	Solution sol;
	int ans = sol.maxProduct(nums);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

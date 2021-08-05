#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int m = nums.size();
        if (m < 2) {
            return false;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < m; i++) {
            remainder = (remainder + nums[i]) % k;
            if (mp.count(remainder)) {
                int prevIndex = mp[remainder];
                if (i - prevIndex >= 2) {
                    return true;
                }
            } else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums {23,2,4,6,7};
	Solution sol;
	cout<<"ans is:"<<sol.checkSubarraySum(nums, 6)<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> rec;
        for (int i = 0; i < n; i++) {
            auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }
            rec.insert(nums[i]);
            if (i >= k) {
                rec.erase(nums[i - k]);
            }
        }
        return false;
    }
};
int main(int argc, char *argv[])
{
	int k = 2;
	int t = 3;
	vector<int> nums {1,5,9,1,5,9};
	Solution sol;
	bool ans = sol.containsNearbyAlmostDuplicate(nums, k, t);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

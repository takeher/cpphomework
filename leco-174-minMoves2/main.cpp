#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int> &nums) {
        int mid = static_cast<int>(nums.size()) / 2, ans = 0;
        nth_element(begin(nums), next(begin(nums), mid), end(nums));
        for_each(begin(nums), end(nums), [&](int num) { ans += abs(num - nums[mid]); });
        return ans;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums{1,2,3};
	Solution sol;
	cout<<"ans is:"<<sol.minMoves2(nums)<<endl;
	return 0;
}

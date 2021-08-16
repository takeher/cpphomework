#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
	bool increasingTriplet(vector<int>& nums)
	{
		int len = nums.size();
		if (len < 3) return false;
		int small = INT_MAX, mid = INT_MAX;
		for (auto num : nums) {
			if (num <= small) {
				small = num;
			}
			else if (num <= mid) {
				mid = num;
			}
			else if (num > mid) {
				return true;
			}
		}
		return false;
	}
};
int main(int argc, char* argv[])
{
	vector<int> nums{1, 2, 3, 4, 5};
	Solution sol;
	cout << "ans is:" << sol.increasingTriplet(nums) << endl;
	return 0;
}

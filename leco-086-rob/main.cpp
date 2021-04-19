#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
	int rob(vector<int>& nums)
	{
		int prev = 0;
		int curr = 0;

		// 每次循环，计算“偷到当前房子为止的最大金额”
		for (int i : nums) {
			// 循环开始时，curr 表示 dp[k-1]，prev 表示 dp[k-2]
			// dp[k] = max{ dp[k-1], dp[k-2] + i }
			int temp = max(curr, prev + i);
			prev = curr;
			curr = temp;
			// 循环结束时，curr 表示 dp[k]，prev 表示 dp[k-1]
		}

		return curr;
	}
};
int main(int argc, char* argv[])
{
	vector<int> nums{1, 2, 3, 1};
	Solution sol;
	int ans = sol.rob(nums);
	cout << "ans is:" << ans << endl;
	return 0;
}

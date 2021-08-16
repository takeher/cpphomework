#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
	int numSquares(int n)
	{
		vector<int> dp(n + 1, n + 1);
		dp[0] = 0;
		int count = 1;
		while (count * count < n) {
			count++;
		}
		if (count * count == n) return 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < count; j++) {
				if (j * j <= i) {
					dp[i] = min(dp[i], dp[i - j * j] + 1);
				}
			}
		}
		return dp[n];
	}
};
int main(int argc, char *argv[])
{
	Solution sol;
	cout << "ans is:" << sol.numSquares(12) << endl;
	return 0;
}

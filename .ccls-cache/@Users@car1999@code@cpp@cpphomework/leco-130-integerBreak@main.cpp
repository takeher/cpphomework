#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        vector <int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = max(max(2 * (i - 2), 2 * dp[i - 2]), max(3 * (i - 3), 3 * dp[i - 3]));
        }
        return dp[n];
    }
};
int main(int argc, char *argv[])
{
	Solution sol;
	cout<<"ans is:"<<sol.integerBreak(10)<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0, n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(matrix[i-1][j-1] == '1')
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};
int main(int argc, char *argv[])
{
	vector<vector<char>> matrix;
	vector<char> r1 {'1','0','1','0','0'};matrix.push_back(r1);
	vector<char> r2 {'1','0','1','1','1'};matrix.push_back(r2);
	vector<char> r3 {'1','1','1','1','1'};matrix.push_back(r3);
	vector<char> r4 {'1','0','0','1','0'};matrix.push_back(r4);
	Solution sol;
	int ans  = sol.maximalSquare(matrix);
	cout<<"ans is:"<<ans<<endl;
	
	return 0;
}

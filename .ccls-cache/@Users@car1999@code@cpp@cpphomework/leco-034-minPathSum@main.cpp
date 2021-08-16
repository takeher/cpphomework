#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size(), columns = grid[0].size();
        auto dp = vector<vector<int>>(rows, vector<int>(columns));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < columns; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][columns - 1];
    }
};
int main(int argc, char *argv[])
{
	vector<vector<int>> grid;
	vector<int> r1{1,3,1};grid.push_back(r1);
	vector<int> r2{1,5,1};grid.push_back(r2);
	vector<int> r3{4,2,1};grid.push_back(r3);
	Solution sol;
	int ans = sol.minPathSum(grid);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

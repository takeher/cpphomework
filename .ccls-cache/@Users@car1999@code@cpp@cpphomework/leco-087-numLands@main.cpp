#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};
int main(int argc, char *argv[])
{
	vector<char> r1 {'1','1','1','1','0'};
	vector<char> r2 {'1','1','0','1','0'};
	vector<char> r3 {'1','1','0','0','0'};
	vector<char> r4 {'0','0','0','0','0'};
	vector<vector<char>> grid;
	grid.push_back(r1);
	grid.push_back(r2);
	grid.push_back(r3);
	grid.push_back(r4);
	Solution sol;
	int ans =sol.numIslands(grid);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

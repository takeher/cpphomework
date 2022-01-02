#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    queue<pair<int, int>> points;
    vector<int> direction = {-1, 0, 1, 0, -1};
    void dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 2;
        for (int k = 0; k < 4; k++) {
            int x = i + direction[k];
            int y = j + direction[k + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                if (grid[x][y] == 2) continue;
                if (grid[x][y] == 1) dfs(grid, x, y);
                // 收集这个岛屿附近的0
                if (grid[x][y] == 0) points.push({x, y});
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // 找到第一个岛屿
        bool isFind = false;
        for (int i = 0; i < m; i++) {
            if (isFind) break;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // 调用dfs把这个岛屿都标志为2
                    dfs(grid, i, j);
                    isFind = true;
                    break;
                }
            }
        }
        // 找另一个岛屿 BFS
        int res = 0;
        while (!points.empty()) {
            int size = points.size();
            res++;
            while (size--) {
                auto [x, y] = points.front();
                points.pop();
                // 把这一层的0全部填为2，再把外层的0再加入队列，逐层填陆地，直到碰到第二片岛屿
                for (int k = 0; k < 4; k++) {
                    int p = x + direction[k];
                    int q = y + direction[k + 1];
                    if (p >= 0 && p < m && q >= 0 && q < n) {
                        if (grid[p][q] == 1) return res;
                        if (grid[p][q] == 2) continue;
                        points.push({p, q});
                        grid[p][q] = 2;
                    }
                }
            }
        }
        return res;
    }
};
int main(){
  auto grid = vector<vector<int>> {vector<int>{1, 0}, vector<int> {0, 1}};
  cout<<"ans is:"<<(new Solution())->shortestBridge(grid)<<endl;
  return 0;
}

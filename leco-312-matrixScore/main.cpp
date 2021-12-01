#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int matrixScore(vector<vector<int>> &grid) {
    auto copy(grid);
    int n = copy.size(), m = copy[0].size();
    for (int i = 0; i < n; i++) {
      if (copy[i][0] == 0) {
        for (int j = 0; j < m; j++) {
          copy[i][j] ^= 1;
        }
      }
    }
    int ans = n * (1 << (m - 1));
    for (int i = 1; i < m; i++) {
      int cnt0 = 0;
      for (int j = 0; j < n; j++) {
        if (copy[j][i] == 0)
          cnt0++;
      }
      ans += max(cnt0, n - cnt0) * (1 << (m - i - 1));
    }
    return ans;
  }
};
int main(){
  //[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
  auto grid =
      vector<vector<int>>{vector<int>{0, 0, 1, 1}, vector<int>{1, 0, 1, 0},
                          vector<int>{1, 1, 0, 0}};
  cout<<"ans is:"<<(new Solution())->matrixScore(grid)<<endl;
  return 0;
}

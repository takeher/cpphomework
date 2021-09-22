#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int xx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
  int yy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
  double knightProbability(int n, int k, int row, int column) {

    int cnt1 = 0;
    dfs(n, k, row, column, cnt1);
    return (double)cnt1 / pow(8, k);
  }
  void dfs(int n, int k, int x, int y, int &cnt1) {
    if (k == 0) {
      cnt1++;
      return;
    }
    for (int i = 0; i < 8; i++) {
      int dx = xx[i] + x, dy = yy[i] + y;
      if (dx < 0 || dx >= n || dy < 0 || dy >= n) {
        continue;
      }
      dfs(n, k - 1, dx, dy, cnt1);
    }
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->knightProbability(3, 2, 0, 0)<<endl;
  return 0;
}

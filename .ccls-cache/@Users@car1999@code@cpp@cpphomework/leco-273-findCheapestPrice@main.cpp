#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  static constexpr int INF = 10000 * 101 + 1;

public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    vector<vector<int>> f(k + 2, vector<int>(n, INF));
    f[0][src] = 0;
    for (int t = 1; t <= k + 1; ++t) {
      for (auto &&flight : flights) {
        int j = flight[0], i = flight[1], cost = flight[2];
        f[t][i] = min(f[t][i], f[t - 1][j] + cost);
      }
    }
    int ans = INF;
    for (int t = 1; t <= k + 1; ++t) {
      ans = min(ans, f[t][dst]);
    }
    return (ans == INF ? -1 : ans);
  }
};
int main(){
  // n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
  auto flights = vector<vector<int>> {vector<int>{0,1,100},vector<int>{1,2,100},vector<int>{0,2,500}};
  cout<<"ans is:"<<(new Solution())->findCheapestPrice(3, flights, 0, 2, 1)<<endl;
  return 0;
}

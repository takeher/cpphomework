#include <bits/stdc++.h>
using namespace std;

#define xy(x, y) (1 << 15) * x + y
class Solution {
public:
  int minAreaRect(const vector<vector<int>> &points) {
    unordered_set<int> mp;
    for (int i = 0; i < points.size(); i++) {
      int x = points[i][0], y = points[i][1];
      mp.insert(xy(x, y));
    }
    int ans = INT_MAX;
    for (int i = 0; i < points.size(); i++) {
      int x0 = points[i][0], y0 = points[i][1];
      for (int j = i + 1; j < points.size(); j++) {
        int x1 = points[j][0], y1 = points[j][1];
        if (x0 == x1 || y0 == y1)
          continue;
        if (mp.count(xy(x0, y1)) && mp.count(xy(x1, y0))) {
          ans = min(ans, abs(x0 - x1) * abs(y0 - y1));
        }
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->minAreaRect(vector<vector<int>> {vector<int>{1,1},vector<int>{1,3},vector<int>{3,1},vector<int>{3,3},vector<int>{2,2}});
  return 0;
}

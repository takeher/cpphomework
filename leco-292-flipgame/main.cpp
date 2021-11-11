#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int flipgame(const vector<int> &fronts, const vector<int> &backs) {
    // 用一个裸数组来做hash表提高性能
    bool exists[2000];
    memset(exists, 0, sizeof(exists));
    int n = fronts.size();
    for (int i = 0; i < n; ++i) {
      if (fronts[i] == backs[i]) {
        exists[fronts[i]] = true;
      }
    }

    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      if (!exists[fronts[i]]) {
        res = min(res, fronts[i]);
      }
      if (!exists[backs[i]]) {
        res = min(res, backs[i]);
      }
    }

    return res == INT_MAX ? 0 : res;
  }
};
int main(){
  cout << "ans is:"<< (new Solution())->flipgame(vector<int>{1,2,4,4,7}, vector<int>{1,3,4,1,3})<<endl;
  return 0;
}

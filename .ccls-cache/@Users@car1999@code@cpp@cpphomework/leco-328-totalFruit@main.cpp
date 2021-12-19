#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int totalFruit(const vector<int> &tree) {
    int res = 0;
    // 水果编号到数量的映射
    unordered_map<int, int> veg2cnt;
    int n = tree.size();
    // 窗口左边界
    int l = 0;
    // 窗口右边界
    for (int i = 0; i < n; ++i) {
      ++veg2cnt[tree[i]];
      // 一旦发现超过大小，则不断收缩窗口
      while (veg2cnt.size() > 2) {
        int currTree = tree[l];
        --veg2cnt[currTree];
        if (veg2cnt[currTree] == 0) {
          veg2cnt.erase(currTree);
        }
        ++l;
      }
      // 记录最大的窗口大小
      res = max(res, i - l + 1);
    }
    return res;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->totalFruit(vector<int> {1,2,1})<<endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int partitionDisjoint(const vector<int> &nums) {
    int n = nums.size();
    int pos = 0;
    int allMax = nums[0];
    int leftMax = nums[0];
    for (int i = 1; i < n; ++i) {
      allMax = max(allMax, nums[i]);
      if (nums[i] < leftMax) {
        leftMax = allMax;
        pos = i;
      }
    }
    return pos + 1;
  }
};
int main(){
  cout << "ans is:"
       << (new Solution())->partitionDisjoint(vector<int>{5, 0, 3, 8, 6})
       << endl;
  return 0;
}

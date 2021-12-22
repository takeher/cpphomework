#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int smallestRangeII(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    int n = nums.size();
    for (int cut = 0; cut < n - 1; cut++) {
      int minNum = nums[0] + k, maxNum = nums[n - 1] - k;
      maxNum = max(maxNum, nums[cut] + k);
      minNum = min(minNum, nums[cut + 1] - k);
      ans = min(ans, maxNum - minNum);
    }
    ans = min(ans, nums[n - 1] - nums[0]);
    return ans == INT_MAX ? 0 : ans;
  }
};
int main(){
  auto nums = vector<int> {1};
  cout<<"ans is:"<<(new Solution())->smallestRangeII(nums, 0)<<endl;
  return 0;
}

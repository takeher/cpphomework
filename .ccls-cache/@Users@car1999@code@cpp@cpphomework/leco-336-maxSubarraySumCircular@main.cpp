#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubarraySumCircular(const vector<int> &nums) {
    int n = nums.size();
    // 这里用一个变量就可以实现循环计算包含当前值（nums[i]）的和的最大值和最小值
    int lastMax = nums[0];
    int lastMin = nums[0];
    int sum = nums[0];
    // 保持全局的和的最大值和最小值
    int maxMax = nums[0];
    int minMin = nums[0];

    for (int i = 1; i < n; ++i) {
      lastMax = max(lastMax + nums[i], nums[i]);
      maxMax = max(maxMax, lastMax);
      lastMin = min(lastMin + nums[i], nums[i]);
      minMin = min(minMin, lastMin);
      sum += nums[i];
    }

    // cout << sum << " " << maxMax << " " << minMin << endl;
    return max(maxMax, sum - minMin == 0 ? (maxMax) : (sum - minMin));
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->maxSubarraySumCircular(vector<int> {1,-2,3,-2})<<endl;
  return 0;
}

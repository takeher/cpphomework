#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string optimalDivision(const vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return to_string(nums[0]);
    } else if (n == 2) {
      return to_string(nums[0]) + "/" + to_string(nums[1]);
    }

    // 开头需要用(来分隔
    string res = to_string(nums[0]) + "/(";
    for (int i = 1; i < n - 1; ++i) {
      res += to_string(nums[i]) + "/";
    }
    // 解围需要)
    res += to_string(nums.back()) + ")";
    return res;
  }
};
int main(){
  cout << "ans is:" << (new Solution())->optimalDivision(vector<int>{1000, 100, 10, 2}) << endl;
  return 0;
}

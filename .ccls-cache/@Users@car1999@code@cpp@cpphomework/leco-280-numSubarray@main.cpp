#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSubarrayBoundedMax(const vector<int> &nums, int left, int right) {
    int lastR = -1;
    int lastD = 0;
    int res = 0;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] > right) {
        lastR = i;
        lastD = 0;
      } else if (nums[i] < left) {
        res += lastD;
      } else {
        lastD = i - lastR;
        res += lastD;
      }
    }
    return res;
  }
};
int main(){
  cout << "ans is:"
       << (new Solution())
    ->numSubarrayBoundedMax(vector<int>{2,1,4,3}, 2,3)<<endl;
  return 0;
}

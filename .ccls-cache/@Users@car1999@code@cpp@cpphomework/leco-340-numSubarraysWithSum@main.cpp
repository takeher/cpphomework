#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSubarraysWithSum(const vector<int> &nums, int goal) {
    int sum = 0;
    unordered_map<int, int> cnt;
    int ret = 0;
    for (auto &num : nums) {
      cnt[sum]++;
      sum += num;
      ret += cnt[sum - goal];
    }
    return ret;
  }
};
int main(){
  cout << "ans is:"
       << (new Solution())
    ->numSubarraysWithSum(vector<int>{1,0,1,0,1}, 2);
  return 0;
}

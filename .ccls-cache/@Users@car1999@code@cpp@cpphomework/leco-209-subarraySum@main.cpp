#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int subarraySum(const vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, pre = 0;
    for (auto &x : nums) {
      pre += x;
      if (mp.find(pre - k) != mp.end()) {
        count += mp[pre - k];
      }
      mp[pre]++;
    }
    return count;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->subarraySum(vector<int> {1,1,1}, 2)<<endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isIdealPermutation(const vector<int> &nums) {
    int n = nums.size();
    int low = n;
    for (int i = n - 1; i >= 2; --i) {
      low = min(low, nums[i]);
      if (nums[i - 2] > low) {
        return false;
      }
    }
    return true;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->isIdealPermutation(vector<int> {1,0,2})<<endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    sort(nums.begin(),nums.end());
    return nums;
  };
};
int main(){
  auto nums = vector<int>{4,2,1,3};
  cout<<"ans is:";
  auto ans = (new Solution())->sortArray(nums);
  for_each(ans.begin(),ans.end(),[](int x){cout<<x<<" ";});
  return 0;
}

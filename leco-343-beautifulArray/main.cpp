#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> beautifulArray(int n) {
    if (n == 1)
      return {1};
    if (n == 2)
      return {1, 2};
    if (n == 3)
      return {1, 3, 2};
    auto vecBLeft = beautifulArray((n + 1) / 2);
    auto vecBRight = beautifulArray(n / 2);
    for (auto &num : vecBLeft)
      num = num * 2 - 1;
    for (auto &num : vecBRight)
      num = num * 2;
    vecBLeft.insert(vecBLeft.end(), vecBRight.begin(), vecBRight.end());
    return vecBLeft;
  }
};
int main(){
  auto ans = (new Solution())->beautifulArray(4);
  for_each(ans.begin(),ans.end(),[](int x){cout<<x<<" ";} );
  return 0;
}

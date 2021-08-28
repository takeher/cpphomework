#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findClosestElements(const vector<int> &arr, int k, int x) {
    int l = 0;
    int r = arr.size() - k;
    while (l < r) {
      int m = (l + r) / 2;
      if (x - arr[m] > arr[m + k] - x) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    // 返回从low开始的k长度的数组
    return vector<int>(arr.begin() + l, arr.begin() + k + l);
  }
};
int main(){
  cout << "ans is:";
  auto ans =  (new Solution())->findClosestElements(vector<int> {1,2,3,4,5}, 4, 3);
  for_each(ans.begin(), ans.end(), [](int x){cout<<x<<" ";});
  return 0;
}

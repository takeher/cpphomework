#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subarrayBitwiseORs(vector<int> &arr) {
    unordered_set<int> res;
    int n = arr.size();
    if (n < 2) {
      return n;
    }

    for (int i = 0; i < n; ++i) {
      res.insert(arr[i]);
      for (int j = i - 1; j >= 0; --j) {
        // 发现一样的数字，则后续无需计算，因为前面数字会计算来避免重复
        if ((arr[j] & arr[i]) == arr[i]) {
          break;
        }
        arr[j] |= arr[i];
        res.insert(arr[j]);
      }
    }
    return res.size();
  }
};
int main(){
  auto arr = vector<int> {0};
  cout<<"ans is:"<<(new Solution())->subarrayBitwiseORs(arr)<<endl;
  return 0;
}

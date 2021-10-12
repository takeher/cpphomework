#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int reachNumber(int target) {
    if (target < 0) {
      target = -target;
    }

    int res = 1;
    // 不算增加去找满足条件最小值
    while (true) {
      int curr = (res + 1) * res / 2;
      if ((curr - target) >= 0 && ((curr - target) % 2) == 0) {
        return res;
      }
      ++res;
    }

    return 0;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->reachNumber(3)<<endl;
  return 0;
}

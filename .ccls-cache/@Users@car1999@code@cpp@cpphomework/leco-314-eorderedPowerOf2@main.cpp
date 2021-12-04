#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool check(int targ, int num) {
    int a[10];
    memset(a, 0, sizeof(a));
    int b[10];
    memset(b, 0, sizeof(b));
    while (targ != 0)
      ++a[targ % 10], targ /= 10;
    while (num != 0)
      ++b[num % 10], num /= 10;
    for (int x = 0; x < 10; x++)
      if (a[x] != b[x])
        return false;
    return true;
  }

  bool reorderedPowerOf2(int n) {
    for (int i = 0; i < 31; ++i)
      if (check((int)pow(2, i), n) == true)
        return true;
    return false;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->reorderedPowerOf2(2)<<endl;
  return 0;
}

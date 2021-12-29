#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int n = (int)s.size();
    int presum[n + 1];
    memset(presum, 0, sizeof(presum));
    for (int i = 0; i < n; i++)
      presum[i + 1] = presum[i] + (s[i] == '1');

    int res = n;
    for (int mid = 0; mid < n + 1; mid++) //左侧有mid个数字，s[mid]属于右侧
    {
      int L1 = presum[mid];
      int R0 = (n - mid) - (presum[n] - presum[mid]);
      res = min(res, L1 + R0);
    }
    return res;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->minFlipsMonoIncr("00110")<<endl;
  return 0;
}

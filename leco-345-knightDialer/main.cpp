#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mod = 1000000007;
  int knightDialer(int N) {
    if (N == 1)
      return 10;
    long a = 1, b = 4, c = 2, d = 2;
    for (int i = 1; i < N; i++) {
      long bn = (2 * c + 2 * d) % mod;
      long cn = (2 * a + b) % mod;
      a = c;
      d = b;
      b = bn;
      c = cn;
    }
    return (a + b + c + d) % mod;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->knightDialer(3)<<endl;
  return 0;
}

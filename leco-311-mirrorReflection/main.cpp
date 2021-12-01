#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mirrorReflection(int p, int q) {
    int gcd = getGcd(p, q);
    int max = p * q / gcd;
    int pp = max / p, qq = max / q;
    if (pp % 2 == 0 && qq % 2 == 1)
      return 0;
    else if (pp % 2 == 1 && qq % 2 == 1)
      return 1;
    else if (pp % 2 == 1 && qq % 2 == 0)
      return 2;
    return -1;
  }
  int getGcd(int a, int b) {
    if (a == 0)
      return b;
    return getGcd(b % a, a);
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->mirrorReflection(2,1)<<endl;
  return 0;
}

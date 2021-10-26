#include <iostream>
using namespace std;

class Solution {
public:
  int numTilings(int n) {
    int base = 1000000007;
    long d[4];
    long d2[4];
    memset(d, 0, sizeof(d));
    memset(d, 0, sizeof(d2));

    d[0] = 1;
    d[1] = 0;
    d[2] = 0;
    d[3] = 1;
    for (int i = 1; i < n; ++i) {
      d2[0] = d[3] % base;
      d2[1] = (d[0] + d[2]) % base;
      d2[2] = (d[0] + d[1]) % base;
      d2[3] = (d[0] + d[1] + d[2] + d[3]) % base;
      memcpy(d, d2, sizeof(d));
    }

    return d[3];
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->numTilings(3)<<endl;
  return 0;
}

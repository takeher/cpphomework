#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int kthGrammar(int N, int K) {
    if (N > 1) {
      // return ((~K) & 1) ^ (kthGrammar(N-1, (K+1)/2));
      return (1 - K % 2) ^ (kthGrammar(N - 1, (K + 1) / 2));
    } else {
      return 0;
    }
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->kthGrammar(1, 1)<<endl;
  return 0;
}

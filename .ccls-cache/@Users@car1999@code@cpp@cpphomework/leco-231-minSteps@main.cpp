#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minSteps(int n) { return dfs(n); }
  int dfs(int n) {
    if (n == 1)
      return 0;
    int newN = getN(n);
    return n / newN + dfs(newN);
  }
  int getN(int n) {
    for (int i = 2; i <= n; i++) {
      if (n % i == 0)
        return n / i;
    }
    return -1;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->minSteps(2)<<endl;
  return 0;
}

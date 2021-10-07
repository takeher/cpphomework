#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int monotoneIncreasingDigits(int n) {
    string strN = to_string(n);
    int i = 1;
    while (i < strN.length() && strN[i - 1] <= strN[i]) {
      i += 1;
    }
    if (i < strN.length()) {
      while (i > 0 && strN[i - 1] > strN[i]) {
        strN[i - 1] -= 1;
        i -= 1;
      }
      for (i += 1; i < strN.length(); ++i) {
        strN[i] = '9';
      }
    }
    return stoi(strN);
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->monotoneIncreasingDigits(324)<<endl;
  return 0;
}

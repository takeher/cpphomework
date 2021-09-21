#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int repeatedStringMatch(string a, string b) {
    int n = a.size(), m = b.size();
    int cnt = m / n;
    string c;
    for (int i = 0; i < cnt; i++) {
      c += a;
    }
    if (c.find(b) != string::npos)
      return cnt;
    c += a;
    if (c.find(b) != string::npos)
      return cnt + 1;
    c += a;
    if (c.find(b) != string::npos)
      return cnt + 2;
    return -1;
  }
};
int main(){
  cout << "ans is:"<< (new Solution())->repeatedStringMatch("abcd", "cdabcdab")<<endl;
  return 0;
}

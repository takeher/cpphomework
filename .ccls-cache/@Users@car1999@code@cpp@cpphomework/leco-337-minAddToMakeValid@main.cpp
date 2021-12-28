#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minAddToMakeValid(string s) {
    int n = s.size();
    int cnt = 0;
    int ans = 0;
    for (auto &c : s) {
      if (c == '(') {
        cnt++;
      } else if (c == ')') {
        if (cnt > 0)
          cnt--;
        else
          ans++;
      }
    }
    ans += cnt;
    return ans;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->minAddToMakeValid("())")<<endl;
  return 0;;
}

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> findAndReplacePattern(const vector<string> &words, string pattern) {
    vector<string> ans;
    int n = pattern.size();
    for (auto &s : words) {
      if (s.size() != n)
        continue;
      bool flag = false;
      unordered_map<char, char> mp1, mp2;
      for (int i = 0; i < n; i++) {
        char c1 = s[i], c2 = pattern[i];
        if (mp1.count(c1) && mp1[c1] != c2) {
          flag = true;
          break;
        }
        mp1[c1] = c2;
        if (mp2.count(c2) && mp2[c2] != c1) {
          flag = true;
          break;
        }
        mp2[c2] = c1;
      }
      if (flag == false)
        ans.push_back(s);
    }
    return ans;
  }
};
int main(){
  cout<<"ans is:";
  auto ans =
      (new Solution())
          ->findAndReplacePattern(
              vector<string>{"abc", "deq", "mee", "aqq", "dkd", "ccc"},
              "abb");
  for_each(ans.begin(),ans.end(),[](string s){cout<<s<<" ";});
  return 0;
}

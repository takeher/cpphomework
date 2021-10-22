#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> ans;
  vector<string> letterCasePermutation(string s) {
    vector<int> idxs;
    for (int i = 0; i < s.size(); i++) {
      if (isdigit(s[i]))
        continue;
      idxs.push_back(i);
    }
    dfs(0, idxs, s);
    return ans;
  }
  void dfs(int i, vector<int> &idxs, string &s) {
    if (i == idxs.size()) {
      ans.push_back(s);
      return;
    }
    int idx = idxs[i];
    string tmp = s;
    if (islower(tmp[idx])) {
      tmp[idx] = toupper(tmp[idx]);
      dfs(i + 1, idxs, tmp);
    } else {
      tmp[idx] = tolower(tmp[idx]);
      dfs(i + 1, idxs, tmp);
    }
    dfs(i + 1, idxs, s);
  }
};
int main(){
  cout<<"ans is:";
  auto ans = (new Solution())->letterCasePermutation("a1b2");
  for_each(ans.begin(), ans.end(), [](string s){cout<<s<<" ";});
  return 0;
}

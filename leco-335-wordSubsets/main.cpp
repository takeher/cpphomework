#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    int m = words1.size(), n = words2.size();
    vector<int> hash(26);

    for (string &s : words2) {
      vector<int> t(26);
      for (char c : s) {
        int x = c - 'a';
        hash[x] = max(hash[x], ++t[x]);
      }
    }
    vector<string> ans;
    for (string &s : words1) {
      vector<int> t(26);
      for (char c : s) {
        t[c - 'a']++;
      }
      bool ok = 1;
      for (int i = 0; i < 26; ++i) {
        if (t[i] < hash[i])
          ok = 0;
      }
      if (ok)
        ans.emplace_back(s);
    }
    return ans;
  }
};
int main(){
  //["amazon","apple","facebook","google","leetcode"][ "e", "o" ]
  auto word1 = vector<string> {
    "amazon ", " apple ", " facebook", " google ",
        "leetcod"};
  auto word2 = vector<string> {"e", "o"};
  auto ans = (new Solution())->wordSubsets(word1, word2);
  cout<<"ans is:";
  for_each(ans.begin(), ans.end(), [](string s){cout<<s<<" ";});
  return 0;
  }

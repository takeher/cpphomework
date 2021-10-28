#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numMatchingSubseq(string s, const vector<string> &words) {
    int n = s.size();
    vector<vector<int>> idxs2allIdxs(n, vector<int>(26, -1));
    vector<int> idxs(26, -1);
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        idxs2allIdxs[i][j] = idxs[j];
      }
      idxs[s[i] - 'a'] = i;
    }
    int ans = 0;
    for (int i = 0; i < words.size(); i++) {
      int curIdx;
      if (s[0] == words[i][0])
        curIdx = 0;
      else
        curIdx = idxs2allIdxs[0][words[i][0] - 'a'];
      for (int j = 1; j < words[i].size(); j++) {
        if (curIdx == -1)
          break;
        curIdx = idxs2allIdxs[curIdx][words[i][j] - 'a'];
      }
      if (curIdx != -1)
        ans++;
    }
    return ans;
  }
};
int main(){
  cout << "ans is:"
       << (new Solution())
              ->numMatchingSubseq("abcde",
                                  vector<string>{"a", "bb", "acd", "ace"})
       << endl;
  return 0;
}

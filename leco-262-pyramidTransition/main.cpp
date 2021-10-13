#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool pyramidTransition(string bottom, const vector<string> &allowed) {
    unordered_map<string, vector<char>> s2vec;
    for (int i = 0; i < allowed.size(); i++) {
      s2vec[allowed[i].substr(0, 2)].push_back(allowed[i][2]);
    }
    string s;
    return dfs(bottom, s, s2vec);
  }
  bool dfs(string &bottom, string &s,
           unordered_map<string, vector<char>> &s2vec) {
    if (s.size() == bottom.size() - 1) {
      if (bottom.size() == 1)
        return true;
      string newS;
      return dfs(s, newS, s2vec);
    }
    vector<char> &vec = s2vec[bottom.substr(s.size(), 2)];
    for (char c : vec) {
      s.push_back(c);
      if (dfs(bottom, s, s2vec))
        return true;
      s.pop_back();
    }
    return false;
  }
};

int main(){
  cout << "ans is:"
       << (new Solution())
              ->pyramidTransition("BCD",
                                  vector<string>{"BCG", "CDE", "GEA", "FFF"})
       << endl;
  return 0;
}

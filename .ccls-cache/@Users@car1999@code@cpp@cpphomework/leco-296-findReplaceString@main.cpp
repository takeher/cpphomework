#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string findReplaceString(string s, vector<int> &indices,
                           vector<string> &sources, vector<string> &targets) {
    stringstream ss;

    // 构建mark表示是否需要被替换
    int mark[s.size()];
    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < indices.size(); ++i) {
      if (s.substr(indices[i], sources[i].size()) == sources[i]) {
        mark[indices[i]] = i + 1;
      }
    }

    // 默认值是0，所以必须>0才考虑
    int n = s.size();
    int i = 0;
    while (i < n) {
      if (mark[i] == 0) {
        ss << s[i];
        ++i;
      } else {
        ss << targets[mark[i] - 1];
        i += sources[mark[i] - 1].size();
      }
    }

    return ss.str();
  }
};
int main(){
  // S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
  string s = "abcd";
  vector<int> indices{0,2};
  vector<string> sources{"a","cd"};
  vector<string> targets{"eee","ffff"};
  cout<<"ans is:"<<(new Solution())->findReplaceString(s, indices, sources, targets)<<endl;
  return 0;
}

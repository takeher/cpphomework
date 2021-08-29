#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<string>> findDuplicate(const vector<string> &paths) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> um; //文件内容->文件路径
    for (const string &path : paths) {
      istringstream iss(path);
      string dir, tmp;
      iss >> dir;
      while (iss >> tmp) {
        string key, val;
        getKeyAndVal(key, val, tmp, dir);
        um[key].push_back(val);
      }
    }
    for (const auto &p : um) {
      if (p.second.size() > 1) {
        ans.push_back(p.second);
      }
    }
    return ans;
  }

private:
  void getKeyAndVal(string &key, string &val, const string &tmp,
                    const string &dir) {
    int i = 0;
    while (tmp[i] != '(')
      ++i;
    val = dir + "/" + tmp.substr(0, i);
    int j = i + 1;
    while (tmp[j] != ')')
      ++j;
    key = tmp.substr(i + 1, j - i - 1);
  }
};
int main(){
  auto ans =(new Solution())->findDuplicate(vector<string>{
    "root/a 1.txt(abcd) 2.txt(efgh)",
    "root/c 3.txt(abcd)",
    "root/c/d 4.txt(efgh)",
    "root 4.txt(efgh)"
  });
  cout<<"ans is:"<<endl;
  for_each(ans.begin(), ans.end(), [](vector<string> a){for_each(a.begin(), a.end(), [](string s){cout<<s<<" ";});cout<<endl;});
  return 0;
}

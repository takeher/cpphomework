#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string customSortString(string order, string s) {
    unordered_map<char, int> char2idx;
    for (int i = 0; i < order.size(); i++) {
      char2idx[order[i]] = i;
    }
    auto cmp = [&](char &a, char &b) { return char2idx[a] < char2idx[b]; };
    sort(s.begin(), s.end(), cmp);
    return s;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->customSortString("cba", "abcd")<<endl;
  return 0;
}

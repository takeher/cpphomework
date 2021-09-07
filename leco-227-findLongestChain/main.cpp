#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) {
    sort(
        pairs.begin(), pairs.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    int n = pairs.size();
    int res = 1;
    int pre = pairs[0][1];
    for (int i = 1; i < n; ++i) {
      if (pre < pairs[i][0]) {
        pre = pairs[i][1];
        ++res;
      }
    }
    return res;
  }
};
int main(){
  vector<vector<int>> pairs {
    vector<int> {1,2},
    vector<int> {2,3},
    vector<int> {3,4}
  };
  cout<<"ans is:"<<(new Solution())->findLongestChain(pairs)<<endl;
  return 0;
}

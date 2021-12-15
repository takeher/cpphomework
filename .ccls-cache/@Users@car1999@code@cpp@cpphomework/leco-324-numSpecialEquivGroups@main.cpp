#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numSpecialEquivGroups(const vector<string> &A) {
    set<string> jihe;
    for (int i = 0; i < A.size(); i++) {
      string a = "", b = "";
      for (int j = 0; j < A[i].size(); j++) {
        if (j % 2 == 0)
          a += A[i][j];
        else
          b += A[i][j];
      }
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      jihe.insert(a + b);
    }
    return jihe.size();
  }
};
int main(){
  cout << "ans is:"
       << (new Solution())
              ->numSpecialEquivGroups(vector<string>{"abcd", "cdab", "cbad",
                                                     "xyzz", "zzxy", "zzyx"})
       << endl;
  return 0;
}

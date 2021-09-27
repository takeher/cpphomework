#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (int)s1[i];
    }
    for (int j = 0; j < m; j++) {
      sum += (int)s2[j];
    }
    s1 = " " + s1, s2 = " " + s2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s1[i] == s2[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 2 * (int)s1[i];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return sum - dp[n][m];
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->minimumDeleteSum("sea", "eat")<<endl;
  return 0;
}

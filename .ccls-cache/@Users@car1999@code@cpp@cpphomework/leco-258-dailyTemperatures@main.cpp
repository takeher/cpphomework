#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(const vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> ans(n);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
        int previousIndex = s.top();
        ans[previousIndex] = i - previousIndex;
        s.pop();
      }
      s.push(i);
    }
    return ans;
  }
};
int main(){
  auto ans = (new Solution())->dailyTemperatures(vector<int> {30, 60 ,90});
  cout<<"ans is:";
  for_each(ans.begin(), ans.end(), [](int x){cout<<x<<" ";});
  return 0;
}

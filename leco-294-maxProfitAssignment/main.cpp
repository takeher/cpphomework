#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {
    int n = difficulty.size();
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
      vec.push_back({difficulty[i], profit[i]});
    }
    sort(vec.begin(), vec.end());
    sort(worker.begin(), worker.end());
    int i = 0, ans = 0, mx = 0;
    for (int j = 0; j < worker.size(); ++j) {
      while (i < n && vec[i].first <= worker[j]) {
        mx = max(mx, vec[i].second);
        i++;
      }
      ans += mx;
    }
    return ans;
  }
};
int main(){
  cout<<"ans is:";
  auto difficulty = vector<int> {2, 4, 6, 8, 10};
  auto profit = vector<int> {10, 20, 30, 40, 50};
  auto worker = vector<int>  { 4, 5, 6, 7};
  cout<<(new Solution())->maxProfitAssignment(difficulty, profit, worker)<<endl;
  return 0;
  };

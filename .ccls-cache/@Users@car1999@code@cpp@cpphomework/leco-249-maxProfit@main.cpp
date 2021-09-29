#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(const vector<int> &prices, int fee) {
    int n = prices.size();
    int buy = prices[0] + fee;
    int profit = 0;
    for (int i = 1; i < n; ++i) {
      if (prices[i] + fee < buy) {
        buy = prices[i] + fee;
      } else if (prices[i] > buy) {
        profit += prices[i] - buy;
        buy = prices[i];
      }
    }
    return profit;
  }
};
int main(){
  cout << "ans is:"
       << (new Solution())->maxProfit(vector<int>{1, 3, 2, 8, 4, 9}, 2) << endl;
  return 0;
}

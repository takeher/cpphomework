#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numRabbits(const vector<int> &answers) {
    unordered_map<int, int> count;
    for (int y : answers) {
      ++count[y];
    }
    int ans = 0;
    for (auto &[y, x] : count) {
      ans += (x + y) / (y + 1) * (y + 1);
    }
    return ans;
  }
};
int main() { cout << "ans is:" << (new Solution())->numRabbits(vector<int>{1,1,2})<<endl;return 0; }

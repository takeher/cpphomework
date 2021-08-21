#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int arrayNesting(const vector<int> &nums) {
    int n = nums.size();
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (!visited[nums[i]]) {
        int curr = nums[i];
        int cnt = 0;
        do {
          ++cnt;
          curr = nums[curr];
          visited[curr] = true;
        } while (curr != nums[i]);

        res = max(res, cnt);
      }
    }
    return res;
  }
};
int main(){
  cout << "ans is:"
       << (new Solution())->arrayNesting(vector<int> {5, 4, 0, 3, 1, 6, 2})
       << endl;
  return 0;
}

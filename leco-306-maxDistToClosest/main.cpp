#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDistToClosest(const vector<int> &seats) {
    int ans = 0;
    int firstOneIdx = -1, lastOneIdx = -1;
    for (int i = 0; i < seats.size(); i++) {
      if (seats[i] == 0) {
        int j = i;
        i++;
        while (i < seats.size() && seats[i] == 0)
          i++;

        int cnt = i - j;
        ans = max(ans, (cnt + 1) / 2);
      }
      if (i < seats.size()) {
        if (firstOneIdx == -1)
          firstOneIdx = i;
        lastOneIdx = i;
      }
    }
    ans = max(max(ans, firstOneIdx), (int)seats.size() - lastOneIdx - 1);
    return ans;
  }
};
int main(){
  cout << "ans is:"
       << (new Solution())->maxDistToClosest(vector<int>{1, 0, 0, 0, 1, 0, 1})
       << endl;
  return 0;
}

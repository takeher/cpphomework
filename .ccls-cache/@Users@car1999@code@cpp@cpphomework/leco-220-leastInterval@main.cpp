#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int leastInterval(const vector<char> &tasks, int n) {
    int len = tasks.size();
    vector<int> vec(26);
    for (char c : tasks)
      ++vec[c - 'A'];
    sort(vec.begin(), vec.end(), [](int &x, int &y) { return x > y; });
    int cnt = 1;
    while (cnt < vec.size() && vec[cnt] == vec[0])
      cnt++;
    return max(len, cnt + (n + 1) * (vec[0] - 1));
  }
};
int main(){
  cout << "ans is:"
       << (new Solution())->leastInterval(vector<char>{'A', 'A', 'A', 'B', 'B', 'B'}, 2)
       << endl;
  return 0;
}

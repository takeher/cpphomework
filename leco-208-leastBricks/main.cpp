#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int leastBricks(vector<vector<int>> &wall) {
    unordered_map<int, int> timesMap;
    for (vector<int> &vec : wall) {
      int sum = 0;
      for (int i = 0; i < vec.size() - 1; ++i) {
        sum += vec[i];
        timesMap[sum]++;
      }
    }
    int result = 0;
    for (auto &a : timesMap)
      result = max(result, a.second);
    return wall.size() - result;
  }
};
int main(){
  // wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
  vector<vector<int>> wall{
      vector<int>{1, 2, 2, 1}, vector<int>{3, 1, 2}, vector<int>{1, 3, 2},
      vector<int>{2, 4},       vector<int>{3, 1, 2}, vector<int>{1, 3, 1, 1}
  };
  cout<<"ans is:"<<(new Solution())->leastBricks(wall)<<endl;
  return 0;
}

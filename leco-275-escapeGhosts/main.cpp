#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int manhattanDistance(vector<int> &point1, vector<int> &point2) {
    return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
  }

  bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
    vector<int> source(2);
    int distance = manhattanDistance(source, target);
    for (auto &ghost : ghosts) {
      int ghostDistance = manhattanDistance(ghost, target);
      if (ghostDistance <= distance) {
        return false;
      }
    }
    return true;
  }
};
int main(){
  auto ghosts = vector<vector<int>> {vector<int> {1,0},{0,3}};
  auto target = vector<int> {0,1};
  cout<<"ans is:"<<(new Solution())->escapeGhosts(ghosts, target)<<endl;
  return 0;
}

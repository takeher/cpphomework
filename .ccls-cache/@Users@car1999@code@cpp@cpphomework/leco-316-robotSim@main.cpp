#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int curDir = 0;
    int curX = 0, curY = 0;
    set<pair<int, int>> mpObs;
    for (int i = 0; i < obstacles.size(); i++) {
      mpObs.insert({obstacles[i][0], obstacles[i][1]});
    }
    int ans = 0;
    for (int i = 0; i < commands.size(); i++) {
      if (commands[i] == -1)
        curDir = (curDir + 1 + 4) % 4;
      else if (commands[i] == -2)
        curDir = (curDir - 1 + 4) % 4;
      else {
        int addX = dir[curDir][0], addY = dir[curDir][1];
        for (int cnt = commands[i]; cnt > 0; cnt--) {
          if (mpObs.count({curX + addX, curY + addY})) {
            break;
          } else {
            curX += addX, curY += addY;
            ans = max(ans, curX * curX + curY * curY);
          }
        }
      }
    }
    return ans;
  }
};
int main(){
  auto commands = vector<int> { 4, -1, 4, -2, 4 };
  auto obstacles = vector<vector<int>> {vector<int>{2,4}};
  cout<<"ans is:"<<(new Solution())->robotSim(commands, obstacles)<<endl;
  return 0;
}

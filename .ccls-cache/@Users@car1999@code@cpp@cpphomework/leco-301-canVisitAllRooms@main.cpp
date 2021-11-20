#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    queue<int> que;
    int n = rooms.size();
    vector<int> vis(n);
    que.push(0);
    while (!que.empty()) {
      for (int sz = que.size(); sz > 0; sz--) {
        int curRoom = que.front();
        que.pop();
        if (vis[curRoom])
          continue;
        for (int nexRoom : rooms[curRoom]) {
          que.push(nexRoom);
        }
        vis[curRoom] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (vis[i] == 0)
        return false;
    }
    return true;
  }
};
int main(){
  //[[1,3],[3,0,1],[2],[0]]
  auto rooms = vector<vector<int>>{vector<int>{1,2}, vector<int>{3,0,1}, vector<int>{2},vector<int>{0}};
  cout<<"ans is:"<<(new Solution())->canVisitAllRooms(rooms)<<endl;
  return 0;
}

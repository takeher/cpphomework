#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int oneStep = 0;
    int cnt = 0;
    int x = rStart, y = cStart;
    vector<vector<int>> ans;
    while (cnt < rows * cols) {
      for (int j = 0; j < 4; j++) {
        if (j == 0 || j == 2)
          oneStep++;
        for (int i = 0; i < oneStep; i++) {
          if (x >= 0 && x < rows && y >= 0 && y < cols) {
            ans.push_back({x, y});
            cnt++;
          }
          x += dir[j][0], y += dir[j][1];
        }
      }
    }
    return ans;
  }
};
int main(){
  auto ans = (new Solution())->spiralMatrixIII(1, 4, 0, 0);
  cout<<"ans is:";
  for_each(ans.begin(),ans.end(),[](vector<int> v){
    cout<<"[";
    for_each(v.begin(),v.end(),[](int x){cout<<x;});
    cout<<"]";
});
  return 0;
}

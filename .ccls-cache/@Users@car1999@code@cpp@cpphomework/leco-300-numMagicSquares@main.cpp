#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<(int)grid.size()-2;i++){
            for(int j=0;j<(int)grid[0].size()-2;j++){
                if(check(i,j,grid))ans++;
            }
        }
        return ans;
    }
    bool check(int x0,int y0,vector<vector<int>>&grid){
        bool one2nine[9];
        memset(one2nine,0,sizeof(one2nine));
        for(int i=x0;i<x0+3;i++){
            for(int j=y0;j<y0+3;j++){
                if(grid[i][j]==0||grid[i][j]>9)return false;
                if(one2nine[grid[i][j]-1]==true)return false;
                one2nine[grid[i][j]-1]=true;
            }
        }
        int add=grid[x0+2][y0]+grid[x0+1][y0+1]+grid[x0][y0+2];
        for(int i=0,x=x0;i<3;i++,x++){
            if(grid[x][y0]+grid[x][y0+1]+grid[x][y0+2]!=add)return false;
        }
        for(int i=0,y=y0;i<3;i++,y++){
            if(grid[x0][y]+grid[x0+1][y]+grid[x0+2][y]!=add)return false;
        }
        if(grid[x0][y0]+grid[x0+1][y0+1]+grid[x0+2][y0+2]!=add)return false;
        return true;
    }
};
int main(){
  auto grid = vector<vector<int>> {
    {
      vector<int>{4, 3, 8, 4}, vector<int>{9, 5, 1, 9}, vector<int> {
        2, 7, 6, 2
      }
    }};
  cout << "ans is:"
       <<((new Solution())->numMagicSquaresInside(grid))<<endl;
      return 0;
    }

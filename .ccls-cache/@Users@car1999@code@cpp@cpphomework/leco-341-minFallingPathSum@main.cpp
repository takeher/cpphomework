#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(const vector<vector<int>>& matrix) {
        int n = matrix.size();
        int result = 0;
        vector<vector<int> >dp(n,vector<int>(n,0));
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                if(i==0){
                    dp[i][j]=matrix[i][j];
                }
                else if(i>0&&j==0){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+matrix[i][j];
                }
                else if(i>0&&j<n-1){
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+matrix[i][j];
                }
                else if(i>0&&j==n-1){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+matrix[i][j];
                }
            }
        }
        result = dp[n-1][n-1];
        for(int i = 0;i<n;i++){
            if(result>dp[n-1][i]){
                result = dp[n-1][i];
            }
        }
        return result;
    }
};
int main(){
  cout << "ans is:"
       << (new Solution())->minFallingPathSum(vector<vector<int>>{{-48}});
  return 0;
}

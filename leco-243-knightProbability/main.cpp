#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double knightProbability(int P, int K, int i, int j) {
        size_t N=static_cast<size_t>(P);
        vector<vector<double>> dp(N,vector<double>(N,0));
        dp[i][j]=1;
        vector<vector<double>> pre;
        for(int k=0;k<K;k++){
            pre=dp;
            for(size_t i=0;i<N;i++)
                for(size_t j=0;j<N;j++){
                    double D1=(i>=1&&j>=2)?pre[i-1][j-2]:0;
                    double D2=(i>=2&&j>=1)?pre[i-2][j-1]:0;
                    double D3=(i>=2&&j<N-1)?pre[i-2][j+1]:0;
                    double D4=(i>=1&&j<N-2)?pre[i-1][j+2]:0;
                    double D5=(i<N-1&&j>=2)?pre[i+1][j-2]:0;
                    double D6=(i<N-2&&j>=1)?pre[i+2][j-1]:0;
                    double D7=(i<N-2&&j<N-1)?pre[i+2][j+1]:0;
                    double D8=(i<N-1&&j<N-2)?pre[i+1][j+2]:0;
                    dp[i][j]=(D1+D2+D3+D4+D5+D6+D7+D8)/8.0;
                }
        }
        double res=0;
        for(size_t i=0;i<N;i++)
            for(size_t j=0;j<N;j++){
                res+=dp[i][j];
            }
        return res;
    }
};
int main(){
  cout<<"ans is:"<<(new Solution())->knightProbability(3, 2, 0, 0)<<endl;
  return 0;
}

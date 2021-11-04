#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    double soupServings(int N) {
        // 较大N，直接返回1.0
        if (N >= 4000)
        {
            return 1.0;
        }
        // 换算25来归一化
        N = N/ 25 + (N %25 != 0);
        double** d = new double*[N+1];
        for (int i = 0; i <= N; ++i)
        {
            d[i] = new double[N+1];
            memset(d[i], 0, sizeof(double)*(N+1));
        }
        for (int i = 0; i <= N; ++i)
        {
             for (int j = 0; j <= N; ++j)
             {
                 if (i > 0 && j > 0)
                 {
                     d[i][j] = (d[max(i-4, 0)][j] + d[max(i-3, 0)][max(j-1,0)] + d[max(i-2, 0)][max(j-2,0)] + d[max(i-1, 0)][max(j-3,0)])*0.25;
                 }
                 else if (i <= 0 && j <= 0)
                 {
                     d[i][j] = 0.5;
                 }
                 else if (i <= 0 && j > 0)
                 {
                     d[i][j] = 1.0;
                 }
             }
        }

        return d[N][N];
    }
};
int main(){
  cout<<"ans is:"<<(new Solution())->soupServings(50)<<endl;
  return 0;
}

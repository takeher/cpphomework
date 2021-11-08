#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    double largestSumOfAverages(const vector<int>& nums, int K) {
        // 前缀和方便快速计算
        int n = nums.size();
        double sums[n+1];
        memset(sums, 0, sizeof(sums));
        for (int i = 0; i < n; ++i)
        {
            sums[i+1] = sums[i] + nums[i];
        }

        // 一维的数组
        // 和上面分析的区别就是为了这呢一维就可以计算，那么我们这里从后往前去计算，最终结果是d[0]
        double d[n];
        // 初始化
        for (int i = 0; i < n; ++i)
        {
            d[i] = (sums[n]-sums[i])/double(n-i);
        }

        for (int k = 1; k < K; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                // 考虑区间里的j的范围找最大值
                for (int j = i+1; j < n; ++j)
                {
                    d[i] = max(d[i], (sums[j]-sums[i])/(j-i) + d[j]);
                }
            }
        }

        return d[0];
    }
};
int main(){
  cout << "ans is:"<< (new Solution())->largestSumOfAverages(vector<int> {9,1,2,3,9}, 3)<<endl;
  return 0;
}

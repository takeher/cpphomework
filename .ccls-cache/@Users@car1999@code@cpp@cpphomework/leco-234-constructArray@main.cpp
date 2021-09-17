#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i)
        {
            res[i] = i+1;
        }

        // 剩下 k个数字做交换构建 k-1个数字
        int j = 0;
        int l = n-k;
        int r = n;
        // 因为序号和数值差1
        for (int i = n - k - 1; i < n; ++i)
        {
            // 偶数用小数字
            if (j % 2 == 0)
            {
                res[i] = l;
                ++l;
            }
            else
            {
                res[i] = r;
                --r;
            }
            ++j;
        }
        return res;
    }
};
int main()
{
    cout<<"ans is:";
    auto ans = (new Solution())->constructArray(3, 1);
    for_each(ans.begin(), ans.end(), [](int a){cout<<a<<" ";});
    return 0;
}

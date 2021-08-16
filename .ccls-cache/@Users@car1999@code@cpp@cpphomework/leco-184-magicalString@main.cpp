#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int magicalString(int n) {
        // 边缘情况
        if (n == 0)
        {
            return 0;
        }
        if (n <= 3)
        {
            return 1;
        }

        // 默认初始值
        string curr = "122";
        // 翻转的标志位: true 是1，反之则是2
        bool flag = true;
        for (int i = 2; curr.size() < n; ++i)
        {
            // 这里按照数字来决定填充的数量
            int cnt = curr[i] - '0';
            while (cnt > 0)
            {
                curr += flag ? '1' : '2';
                --cnt;
            }
            flag = flag ^ 1;
        }

        // 再次遍历
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res += curr[i] == '1';
        }
        return res;
    }
};
int main(int argc, char *argv[])
{
	Solution sol;
	cout<<"ans is:"<<sol.magicalString(6)<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int res = 0;
    // 保存一个数组来记录是否被访问过，这里故意多留一个0，后续计算无需减1
    bool visisted[16];

    // n表示最大值，start表示当前遍历的值
    void dfs(int n, int start)
    {
        if (start > n)
        {
            // 已经找到一种排列
            ++res;
        }
        for (int i = 1; i <= n; ++i)
        {
            // 只考虑没遍历过且满足条件的情况
            if (!visisted[i] && (start % i == 0 || i % start == 0))
            {
                visisted[i] = true;
                dfs(n, start+1);
                // 关键一步要回溯
                visisted[i] = false;
            }
        }
    }
public:
    int countArrangement(int n) {
        memset(visisted, 0, sizeof(visisted));
        dfs(n, 1);
        return res;
    }
};
int main(int argc, char *argv[])
{
	Solution sol;
	cout<<"ans is:"<<sol.countArrangement(3)<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int start = 1;
        // 步长,会不断加倍
        int step = 1;
        // 判断是从左往右还是从右往左
        bool isLR = true;
        while (n > 1)
        {
            // 从左往右 或者 从右往左奇数个 时候起点才会改变
            if (isLR || (n &1) == 1)
            {
                start += step;
            }
            // 长度减半
            n >>= 1;
            step <<= 1;
            isLR = !isLR;
        }

        return start;
    }
};
int main(int argc, char *argv[])
{
	int n = 9;
	Solution sol;
	cout<<"ans is:"<<sol.lastRemaining(n)<<endl;
	return 0;
}

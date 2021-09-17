#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
private:
    int NumBits(int n)
    {
        int res = 0;
        while (n > 0)
        {
            n = n &(n-1);
            ++res;
        }
        return res;
    }
public:
    int flipLights(int n, int presses) {
        // 记录能看到不同状态的结果，个数就是结果
        unordered_set<int> res;
        n = min(n, 6);
        // 小于6的情况的偏移量
        int offset = max(0, 6-n);
        // 16种可能性 2^4
        for (int c = 0; c < 16; ++c)
        {
            // 达到当前状态最小的操作次数：即bit=1的个数
            int cnt = NumBits(c);
            // 判断是否可达
            if ((cnt % 2 == presses % 2) && (cnt <= presses))
            {
                // 初始状态都不亮
                int curr = 0;
                // 判断是否包含某个操作，是的会会对状态做响应的改动
                if (((c >> 0) & 1) > 0)
                {
                    curr ^= 0b111111 >> offset;
                }
                if (((c >> 1) & 1) > 0)
                {
                    curr ^= 0b010101 >> offset;
                }
                if (((c >> 2) & 1) > 0)
                {
                    curr ^= 0b101010 >> offset;
                }
                if (((c >> 3) & 1) > 0)
                {
                    curr ^= 0b100100 >> offset;
                }
                res.insert(curr);
            }
        }
        return res.size();
    }
};
int main()
{
    cout<<"ans is:"<<(new Solution())->flipLights(1, 1)<<endl;
    return 0;
}

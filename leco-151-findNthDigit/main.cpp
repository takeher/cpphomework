#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        // 先找到digits
        long digits = 1;
        long base = 9;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            ++digits;
        }

        // 找到目标的数字
        // 计算后n是对应的在当前digits下的序号
        // 例子1 位数是3， n=4 表示的是第四个， 对应的数字就是 100 + 3/3 = 101 里的 3%4=1的第一个数字
        // 例子2 位数是3，n=3 表示的是第三个，对应的数字是 100 + 3/3-1 = 100 里的 3%3+3=3的第三个数字
        // 考虑基数 10^(digits-1)
        int t = 1;
        for (int i = 1; i < digits; ++i)
        {
            t *= 10;
        }
        // 这里考虑一下对应的是第几个数字，需要考虑前面提到边缘情况就是正好能被digits整除
        int index = (n % digits == 0) ? digits : n % digits;
        t += index == digits ? n/digits - 1 : n/digits;

        // 按照位数去找对应的一位数字，这里是使用倒序的实现
        // 如果是最后一位，index=digits, 那么一次除法都没有
        // 如果是第一位，index=0, 则需要除digits-1次
        // 总结就是 digits - 位数
        for (int i = index; i < digits; ++i)
        {
            t /= 10;
        }
        // 取10的模得到对应的单个数字
        return t % 10;
    }
};
int main(int argc, char *argv[])
{
	Solution sol;
	cout<<"ans is:"<<sol.findNthDigit(11)<<endl;
	return 0;
}

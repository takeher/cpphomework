#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int nn = s.size();
        // 如果只有1个，直接返回失败
        if (nn <= 1)
        {
            return -1;
        }
        // 先找到最小的数字, 从n-2开始无必然有数字可以比较
        int i = nn - 2;
        for (; i >= 0; --i)
        {
            if (s[i] < s[i+1])
            {
                break;
            }
        }

        // 数组已经是递增，则无法有更大数，返回失败
        if (i < 0)
        {
            return -1;
        }

        // 找到比 s[i] 稍大的 数字 s[j]
        int j = nn-1;
        for (; j >= 0; --j)
        {
            if (s[j] > s[i])
            {
                break;
            }
        }
        swap(s[i], s[j]);

        // 翻转从i+1到end 的数组
        reverse(s.begin()+i+1, s.end());

        // 考虑int溢出的情况
        long res = stol(s);
        return res > INT_MAX ? -1 : res;
    }
};
int main(){
  cout<<"ans is:"<<(new Solution())->nextGreaterElement(12)<<endl;
  return 0;
}

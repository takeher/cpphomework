#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool helper(vector<int8_t>& vis, int& maxChoosableInteger, int num, int desiredTotal) {
        //记忆化，补码的-1 表示为 1111111111... 位运算取反=0，其余数不为0
        if (~vis[num]) return vis[num];
        vis[num] = 0;
        for (int i = 1; i <= maxChoosableInteger; ++i) {
            //表示num中有i了，就continue呗
            if (num & (1 << (i - 1))) continue;
            //如果这次选i能够大于等于desiredTotal这次选的人就赢了啊
            if (i >= desiredTotal) {
                vis[num] = 1;
                break;
            }
            //如果这次选i小于desiredTotal

            //那就给另外的人选，看他能不能赢
            bool next = helper(vis, maxChoosableInteger, num | (1 << (i - 1)), desiredTotal - i);
            //他不能赢，我就赢了拜拜否则选i的情况我赢不了，但是我可以选其它的数，
            //唉，我先选占优势，就是玩。
            if (next == false) {
                vis[num] = 1;
                break;
            }
        }
        return vis[num];
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // 可选择的数如果加起来没有desiredTotal那么大家一起输
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;

        //maxChoosableInteger是20，状态压缩，用一个32位的int表示就行
        //using int8_t = unsigned char; -1表示没有，0 表示输， 1 表示赢，足够
        //注意从1开始 ，那么右移后 - 1
        vector<int8_t> vis((1 << maxChoosableInteger) - 1, -1);
        //num表示现在选取了的数
        int num = 0;
        return helper(vis, maxChoosableInteger, num, desiredTotal);
    }
};
int main(int argc, char *argv[])
{
	Solution sol;
	cout<<"ans is:"<<sol.canIWin(10, 11)<<endl;
	return 0;
}

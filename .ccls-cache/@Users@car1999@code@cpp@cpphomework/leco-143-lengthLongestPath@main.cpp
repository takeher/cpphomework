#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthLongestPath(string input) {
        //这个newline的插入非常重要，因为我们是在要到达下一个newline时才计算
        //如果不加的话我们便计算不到最后一个文件的长度
        input.push_back('\n');
        vector<int> levels(300, 0);
        int lv = 0, ans = 0, len = 0;
        bool is_file = false;

        for(const char & c : input)
        {
            switch(c)
            {
                case '\n': {
                    levels[lv] = len;
                    //我们需要加上 lv，lv代表的是我们"/"的数量
                    //getlen会取得所有包括当前层之前所有层的和
                    if(is_file) ans = max(ans, getLen(levels, lv)+lv);
                    //到达下一层，因此需要reset所有的值重新计算下一层
                    lv = len = 0;
                    is_file = false;
                    break;
                }
                case '\t': ++lv; break;
                //注意这里没有break！！因为它同样也是一个character,也要计算。
                case '.' : is_file = true;
                default: ++len;
            }
        }
        return ans;
    }

    int getLen(vector<int>& levels, int lv)
    {
        int sum = 0;
        for(int i = 0; i <= lv; ++i)
            sum += levels[i];
        return sum;
    }
};
int main(int argc, char *argv[])
{
	string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	Solution sol;
	cout<<"ans is:"<<sol.lengthLongestPath(input)<<endl;
	return 0;
}

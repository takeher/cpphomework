#include<bits/stdc++.h>
using namespace std;
/*
考虑到数据量很大，所以直接用一个数组来保存会有很大时间和空间复杂度
反其道而行之，用一个map来保存哪些随机数已经取过了
随机数我们每次会在一个越来越小的范围里，那么意味着，我们要把那些取过的数字和其他没被选择点交换，然后不断缩小右边界
具体就是把当前选中点和右边界交换，搜索边界后选重点必然不会再被选到
具体参见代码
*/

class Solution {
private:
    int rows;
    int cols;
    int total;
    // 记录哪些被选中的点，而且指向它没被选中的数值，可以用来输出
    unordered_map<int, int> val2real;

public:
    Solution(int n_rows, int n_cols) : rows(n_rows), cols(n_cols){
        total = rows * cols;
    }

    vector<int> flip() {
        // 随机数
        int r = rand() % total;
        -- total;
        // 去判断r是否已经是被选中的数字，是则取map里的真实值，否则直接取值即可
        int curr = r;
        if (val2real.find(r) != val2real.end())
        {
            curr = val2real[r];
        }
        else
        {
            // 得记得更新该值
            val2real[r] = r;
        }
        // 取完后记得要和边界值交换来更新map到真实值
        // 如果边界值已经在map里了，则直接取边界值映射的真实值
        if (val2real.find(total) != val2real.end())
        {
            val2real[r] = val2real[total];
        }
        else
        {
            val2real[total] = total;
            // 注意这里是替换r
            val2real[r] = total;
        }
        return {curr / cols, curr % cols};
    }

    void reset() {
        val2real.clear();
        total = rows * cols;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
int main(int argc, char *argv[])
{
	Solution* obj = new Solution(1,2);
	vector<int> param_1 = obj->flip();
	cout<<"ans is:";
	for(int i = 0;i < param_1.size();++i){
		cout<<param_1[i]<<" ";
	}
	return 0;
}

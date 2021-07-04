#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // 左边界到序号的映射
        unordered_map<int, int> left2index;
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
        {
            left2index[intervals[i][0]] = i;
        }

        // 按照左边界从小到大排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // 遍历二分去找每个的满足条件的最小区间
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i)
        {
            // 当前的右边界
            int right = intervals[i][1];
            int l = 0;
            int r = n-1;
            while (l <= r)
            {
                int m = (l+r) >> 1;
                if (intervals[m][0] >= right)
                {
                    // 这个结果记得去按照左边界找回自己真实的序号
                    res[left2index[intervals[i][0]]] = left2index[intervals[m][0]];
                    r = m-1;
                }
                else
                {
                    l = m+1;
                }
            }
        }
        return res;
    }
};
int main(int argc, char *argv[])
{
	vector<vector<int>> intervals;
	vector<int> i1 {1,2};
	intervals.push_back(i1);
	Solution sol;
	auto ans = sol.findRightInterval(intervals);
	cout<<"ans is:";
	for(int i = 0;i < ans.size();++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}

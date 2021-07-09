#include<bits/stdc++.h>
using namespace std;
/***
暴力却高效的解法
遍历每个点，去找它到各个点的距离
对于距离相同的情况（至少2个点），就存在回旋镖的情况，这里快速计算方式就是 n*(n-1) 个对
如何记录距离呢？ 可以考虑保存在一个map做距离到数量的映射
***/
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        for (int i = 0; i < n; ++i)
        {
            unordered_map<int, int> dist2cnt;
            for (int j = 0; j < n; ++j)
            {
                // 这里计算所有点，减少if判断，自己和自己是0，会忽略
                int dist = pow(points[i][0]-points[j][0], 2) + pow(points[i][1]-points[j][1], 2);
                ++dist2cnt[dist];
            }

            // 再次遍历去找所有距离相同可能构成的回旋镖数量
            for (auto iter = dist2cnt.begin(); iter != dist2cnt.end(); ++iter)
            {
                int num = iter->second;
                res += num * (num-1);
            }
        }
        return res;
    }
};
int main(int argc, char *argv[])
{
	vector<vector<int>> points;
	vector<int> p1 {0,0};
	vector<int> p2 {1,0};
	vector<int> p3 {2,0};
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	Solution sol;
	cout<<"ans is:"<<sol.numberOfBoomerangs(points)<<endl;

	return 0;
}

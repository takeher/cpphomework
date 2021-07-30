#include<bits/stdc++.h>
using namespace std;
/*
思路
1. 因为不重叠，所以无需考虑重叠
2. 把每个矩形面积累加在一起就是总和，而我们随机数就是基于这个面积来取
3. 按照面积就能取到对应的矩形，矩形找到后再按照相对坐标去输出坐标即可

优化
1. 第三步找矩形，因为矩形面积是累加和，是递增的，所以可以用二分法来查找
*/
class Solution {
private:
    // 内部矩阵的构建，包括累加面积和，左下角坐标和的宽度
    // 这样子就能计算对应矩阵里的对应坐标
    vector<vector<int>> rects;
    int sumArea;

    int BinarySearch(int num)
    {
        int l = 0;
        int r = rects.size() - 1;
        int m;
        int bounder = 0;
        while (l <= r)
        {
            m = (l+r) >> 1;
            if (rects[m][0] == num)
            {
                // 正常等于，直接返回即可
                return m;
            }
            else if (rects[m][0] > num)
            {
                r = m-1;
            }
            else
            {
                l = m + 1;
                bounder = m;
            }
        }
        return bounder;
    }

public:
    Solution(vector<vector<int>>& r) {
        sumArea = 0;
        for (vector<int>& rr : r)
        {
            rects.push_back({sumArea, rr[0], rr[1], rr[2]-rr[0]+1});
            // 这里其实是要要额外+1的因为坐标范围是[0,w],[0.h]
            sumArea += (rr[2]-rr[0]+1) * (rr[3]-rr[1]+1);
        }
        // 设置随机种子
        srand(time(nullptr));
    }

    vector<int> pick() {
        // 获取随机数
        int randNum = rand() % sumArea;

        // 二分法找矩形的编号
        int index = BinarySearch(randNum);

        // 面积差值
        int area = randNum - rects[index][0];
        return {rects[index][1] + area % rects[index][3], rects[index][2] + area / rects[index][3]};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
int main(int argc, char *argv[])
{
	vector<vector<int>> rects;
	vector<int> r1 {-2,-2,-1,-1};rects.push_back(r1);
	vector<int> r2 { 1, 0, 3, 0};rects.push_back(r2);
	Solution* obj = new Solution(rects);
	auto ans = obj->pick();
	cout<<"ans is:";
	for(int i = 0;i < ans.size();++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}

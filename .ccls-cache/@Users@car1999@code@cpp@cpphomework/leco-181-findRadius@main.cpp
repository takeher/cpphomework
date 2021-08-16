#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
	/* 对供暖器位置进行升序排序，考察每一栋房子和供暖器的最小距离，
	所有最小距离的最大值，就是答案，最小距离可通过房子和最近的两个供暖器距离取小而得到*/
	int findRadius(vector<int>& houses, vector<int>& heaters)
	{
		// 添加INT_MIN和INT_MAX，保证房子在供暖器的范围之内
		heaters.push_back(INT_MIN);
		heaters.push_back(INT_MAX);
		sort(heaters.begin(), heaters.end());  // 对供暖器位置进行排序
		int ans = 0;
		for (auto value : houses) {
			int left = 0, right = heaters.size() - 1;
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (value > heaters[mid])
					left = mid + 1;
				else
					right = mid;
			}
			// left 指向不小于 value 的最小元素的位置
			ans =
			    max(ans, (int)min(heaters[left] - 0LL - value,
					      value - 0LL - heaters[left - 1]));
			// 0LL是 long long
			// 类型的常量0，计算过程中添加是不影响结果的，并且可以实现类型提升避免溢出
		}
		return ans;
	}
};
int main(int argc, char *argv[])
{
	vector<int> houses {1,2,3};
	vector<int> heaters {2};
	Solution sol;
	cout<<"ans is:"<<sol.findRadius(houses, heaters)<<endl;
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.empty()) return 0;
		int ipx = 0, cnt = 0;
		// ipx为指向下一个要覆盖元素的位置，cnt记录重复元素的数量
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				//如果跟前一项重复，cnt增加
				cnt++;
				if (cnt < 2) {
					//如果出现次数少于2，覆盖
					nums[ipx++] = nums[i];
				}
			}
			else {
				//如果不重复，则覆盖
				cnt = 0;
				nums[ipx++] = nums[i];
			}
		}
		return ipx;  //返回数组长度
	}
};
int main(int argc, char* argv[])
{
	vector<int> nums{1, 1, 1, 2, 2, 3};
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	Solution sol;
	int ans = sol.removeDuplicates(nums);
	cout << endl;
	cout << "ans is:" << ans << endl;
	return 0;
}

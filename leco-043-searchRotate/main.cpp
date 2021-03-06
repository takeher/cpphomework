#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return false;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = ((right - left) >> 2) + left;
            if (nums[mid] == target)
                return true;

            if (nums[mid] == nums[left]) {
                ++left;
                continue;
            }

            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums{2,5,6,0,0,1,2};
	int target = 0;
	Solution sol;
	bool ans = sol.search(nums, target);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

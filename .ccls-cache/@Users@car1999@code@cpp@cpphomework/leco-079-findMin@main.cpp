#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else {
                low = pivot + 1;
            }
        }
        return nums[low];
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums {3,4,5,1,2};
	Solution sol;
	int ans = sol.findMin(nums);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

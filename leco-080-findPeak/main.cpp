#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int left =  0, right = nums.size() - 2;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 2);
            if(nums[mid] > nums[mid+1])
                right = mid - 1;
            else if(nums[mid] < nums[mid+1])
                left = mid + 1;
            else{}
        }
        return right + 1;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums {1,2,3,1};
	Solution sol;
	int ans = sol.findPeakElement(nums);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

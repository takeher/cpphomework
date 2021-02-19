#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }

};
int main(int argc, char *argv[])
{
	vector<int> nums {2,3,1,1,4};
	Solution sol;
	bool ans = sol.canJump(nums);
	cout<<"ans is :"<<ans<<endl;
	return 0;
}

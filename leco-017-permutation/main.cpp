#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	//next_permutation(nums.begin(), nums.end());
	        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums = {1,2,3};
	Solution sol;
	sol.nextPermutation(nums);
	for(int i = 0;i<nums.size();++i){cout<< nums[i]<<" ";}
	return 0;
}

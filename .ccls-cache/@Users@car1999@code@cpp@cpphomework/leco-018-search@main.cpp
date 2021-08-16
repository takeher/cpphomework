#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
	int l = nums.size();
	int ans = 0;
	if(l == 1){
		if(target == nums[0]){return 0;}
		else{return -1;}
	}
	if( target > nums[0]){
		for(int i = 0;i < l;++i){
			if(nums[i] > nums[i + 1]){
				if(nums[i] != target){return -1;}
				else{ans = i;break;}
			}
			if(target == nums[i]){ans = i;break;}
		}
	}
	else if(target < nums[l - 1]){
		for(int i = 0;i < l;++i){
			if(nums[l - 2 - i] > nums[l - 1 - i]){
				if(nums[l - 1 - i] != target){return -1;}
				else{ans = l - 1 - i;break;}
			}
			if(target == nums[i]){ans = i;break;}
		}
	}
	else{
		return -1;
	}
	return ans;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums{4,5,6,7,0,1,2};
	int target = 0;
	Solution sol;
	int ans = sol.search(nums, target);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return sort(nums.begin(), nums.end(), greater<int>()), nums[k - 1];
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums {3,2,1,5,6,4};
	int k = 2;
	Solution sol;
	int ans = sol.findKthLargest(nums, k);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(const vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid + 1]) {
                lo = mid + 2;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};
int main(int argc, char *argv[])
{
	cout<<"ans is:"<<(new Solution())->singleNonDuplicate(vector<int> {1,1,2,3,3,4,4,8,8})<<endl;
	return 0;
}

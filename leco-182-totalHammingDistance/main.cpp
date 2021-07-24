#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < 30; ++i) {
            int c = 0;
            for (int val : nums) {
                c += (val >> i) & 1;
            }
            ans += c * (n - c);
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums{4,14,2};
	Solution sol;
	cout<<"ans is:"<<sol.totalHammingDistance(nums)<<endl;
	return 0;
}

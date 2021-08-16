#include<bits/stdc++.h>
using namespace std;
//一直判断当前数字应该在的位置是否已经有正确的数字，如果有说明重复，直接加进答案中，i++；如果没有，那就和正确位置的数字交换，继续判断；
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> ret;
        int i=0;
        while(i<n){
            if(nums[i]==i+1)
                i++;
            else{
                int t=nums[i];
                if(nums[t-1]==t){
                    ans[t-1]++;
                    i++;
                }
                else
                    swap(nums[t-1],nums[i]);
            }
        }
        for(int i=0;i<n;++i){
            if(ans[i])
                ret.push_back(i+1);
        }
        return ret;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums {4,3,2,7,8,2,3,1};
	Solution sol;
	cout<<"ans is:";
	for(auto i : sol.findDuplicates(nums)){
		cout<<i<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long  sum=0,n=nums.size(),pos=n-1,fst=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            fst+=i*nums[i];
        }
        long long zqmax=fst;
        for(int i=0;i<n;i++){
            fst=fst-n*nums[pos]+sum;
            pos--;
            zqmax=max(zqmax,fst);
        }
        return zqmax;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums {4, 3, 2, 6};
	Solution sol;
	cout<<"ans is:"<<sol.maxRotateFunction(nums)<<endl;
	return 0;
}

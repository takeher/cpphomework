#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();

        auto nxt=[nums,n](int cur){
            return ((cur+nums[cur])%n+n)%n;
        };

        for(int i=0;i<n;++i){
            if(!nums[i]) continue;
            int slow=i,fast=nxt(i);
            while(nums[i]*nums[fast]>0 && nums[i]*nums[nxt(fast)]>0){
                if(slow==fast){
                    if(slow!=nxt(slow)) return true;
                    break;
                }
                slow=nxt(slow);
                fast=nxt(nxt(fast));
            }
            int dir=nums[i],p=i;
            while(dir*nums[p]>0){
                int np=nxt(p);
                nums[p]=0;
                p=np;
            }
        }
        return false;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums {2,-1,1,2,2};
	Solution sol;
	cout<<"ans is:"<<sol.circularArrayLoop(nums)<<endl;
	return 0;
}

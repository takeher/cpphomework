#include <bits/stdc++.h>
using namespace std;
// nums = [4, 3, 2, 3, 5, 2, 1], k = 4
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int add=accumulate(nums.begin(),nums.end(),0);
        if(add%k!=0)return false;
        int n=nums.size();
        int target=add/k;
        sort(nums.begin(),nums.end(),greater<int>());
        if(nums[n-1]>target)return false;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            if(!dfs(i+1,target-nums[i],vis,nums))return false;
        }
        return true;
    }
    bool dfs(int beg,int target,vector<int>&vis,vector<int>&nums){
        if(target==0)return true;
        if(beg==nums.size())return false;

        for(int i=beg;i<nums.size();i++){
            if(vis[i])continue;
            if(nums[i]>target)continue;
            vis[i]=1;
            if(dfs(i+1,target-nums[i],vis,nums))return true;
            else vis[i]=0;

        }
        return false;
    }
};
int main(){
  vector<int> nums {4,3,2,3,5,2,1};
  cout << "ans is:"
       << (new Solution())->canPartitionKSubsets(nums, 4)<<endl;
  return 0;
}

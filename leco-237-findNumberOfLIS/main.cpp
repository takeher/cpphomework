#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(const vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        dp[0]=1;
        int maxLen=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j]+1>dp[i]){
                        count[i]=count[j];
                    }else if(dp[j]+1==dp[i]){
                        count[i]+=count[j];
                    }
                    dp[i]=max(dp[i],dp[j]+1);
                    maxLen=max(maxLen,dp[i]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            //cout<<dp[i]<<' '<<maxLen<<endl;
            if(dp[i]==maxLen)ans+=count[i];
        }
        return ans;
    }
};
int main(){
  cout<<"ans is:"<<(new Solution())->findNumberOfLIS(vector<int> {1,3,5,4,7})<<endl;
  return 0;
}

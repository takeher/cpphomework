#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans=0;
        int n=arr.size();
        const int mod=1e9+7;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                long add=arr[i]+arr[j]+arr[k];
                if(add<target)j++;
                else if(add>target)k--;
                else {
                    if(arr[j]==arr[k]){
                        long cntj=1;
                        while(j!=k){
                            j++;
                            cntj++;
                        }
                        ans+=cntj*(cntj-1)/2;
                        ans%=mod;
                    }else {
                        long cntj=1,cntk=1;
                        while(j+1<k&&arr[j+1]==arr[j]){
                            j++,cntj++;
                        }
                        while(k-1>j&&arr[k-1]==arr[k]){
                            k--,cntk++;
                        }
                        ans+=cntj*cntk;                      
                        ans%=mod; 
                    }

                    j++,k--;
                }
            }
        }
        return ans;
    }
};

int main(){
  auto arr = vector<int> {1,1,2,2,3,3,4,4,5,5};
  cout<<"ans is:"<<(new Solution())->threeSumMulti(arr, 8)<<endl;
  return 0;
}

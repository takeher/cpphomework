#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(const vector<int>& asteroids) {
        deque<int>deq;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0)deq.push_back(asteroids[i]);
            else {
                int num=-asteroids[i];
                bool flag=false;
                while(!deq.empty()&&deq.back()>0){
                    if(deq.back()<num)deq.pop_back();
                    else if(deq.back()==num){
                        deq.pop_back();
                        flag=true;
                        break;
                    }else if(deq.back()>num){
                        break;
                    }
                }
                if(!flag&&(deq.empty()||deq.back()<0))deq.push_back(asteroids[i]);
            }
        }
        vector<int>ans;
        while(!deq.empty()){
            ans.push_back(deq.front());
            deq.pop_front();
        }
        return ans;
    }
};
int main(){
  auto ans = (new Solution())->asteroidCollision(vector<int>{5, 10, -5});
  cout<<"ans is:";
  for_each(ans.begin(), ans.end(), [](int x){cout<<x<<" ";});
  return 0;
}

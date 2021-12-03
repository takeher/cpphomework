#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int primePalindrome(int N) {
        int ans = INT_MAX;

        for(int i = 1; i <= 5 && ans == INT_MAX; i ++){
            int a = pow(10, i - 1), b = pow(10, i);
            for(int j = a; j < b; j ++){
                string s = to_string(j);
                
                string a = s;
                for(int i = s.length() - 2; i >= 0; i --)
                    a += s[i];
                long long t = stoll(a);
                if(t < 2e8 && t >= N && isP(t)){
                    if(ans > t)
                        ans = t;
                }

                string b = s;
                for(int i = s.length() - 1; i >= 0; i --)
                    b += s[i];
                t = stoll(b);
                if(t < 2e8 && t >= N && isP(t)){
                    if(ans > t)
                        ans = t;
                }            
            }
        }
        return ans;
    }

    inline bool isP(int a){
        if(a == 1)
            return false;
        int t = sqrt(a);
        for(int i = 2; i <= t; i ++)
            if(a % i == 0)
                return false;
        return true;
    }
};
int main(){
  cout<<"ans is:"<<(new Solution())->primePalindrome(6)<<endl;
  return 0;
}

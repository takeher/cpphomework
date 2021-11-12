#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numFriendRequests(const vector<int>& ages) {
        int cnt[121];
        memset(cnt, 0 , sizeof(cnt));
        for (int age : ages)
        {
            ++cnt[age];
        }

        int res = 0;
        for (int a  = 0; a <= 120; ++a)
        {
            int cntA = cnt[a];
            if (cntA == 0)
            {
                continue;
            }
            for (int b = 0; b <= 120; ++b)
            {
                int cntB = cnt[b];
                if (cntB == 0)
                {
                    continue;
                }
                if ((a*0.5+7 >= b) || (b > a) || (a < 100 && 100 < b))
                {
                    continue;
                }
                {
                    // cout << cntA << " " << cntB << " " << a << " vs " << b << endl;
                    res += cntA * cntB;
                    if (a == b)
                    {
                        res -= cntA;
                    }
                }
            }
        }
    
        return res;
    }
};
int main(){
  cout<<"ans is:"<<(new Solution())->numFriendRequests(vector<int> {16,16})<<endl;
  return 0;
}

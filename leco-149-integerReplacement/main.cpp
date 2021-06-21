#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int integerReplacement(int n) {
        long x = n;
        int ans = 0;
        while(x != 1)
        {
            if(x % 2 == 0)
            {
                ++ans;
                x/=2;
            }
            else
            {
                ans += 2;
                if((x-1)/2%2 == 1)
                {
                    if(x == 3)
                        x/=2;
                    else
                        x = (x+1)/2;
                }
                else
                    x = (x-1)/2;
            }
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
	int n = 8;
	Solution sol;
	cout<< "ans is:"<<sol.integerReplacement(n)<<endl;
	return 0;
}

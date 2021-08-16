#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            // 抹去最右边的 1
            n = n & (n - 1);
        }
        return n;
    }
};
int main(int argc, char *argv[])
{
	int m = 4;
	int n = 7;
	Solution sol;
	int ans = sol.rangeBitwiseAnd(m, n);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0 || b == 0) return a | b;
        return getSum(a^b, (unsigned int)(a&b)<<1);
    }
};
int main(int argc, char *argv[])
{
	int a = 1;
	int b = 2;
	Solution sol;
	cout<<"ans is:"<<sol.getSum(a,b)<<endl;
	return 0;
}

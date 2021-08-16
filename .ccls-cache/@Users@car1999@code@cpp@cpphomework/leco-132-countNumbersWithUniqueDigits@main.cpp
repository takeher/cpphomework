#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int* d = new int[n+1];
        memset(d, 0, sizeof(int)*(n+1));
        for (int i = 2; i < n+1; ++i)
        {
            d[i] = d[i-1]*10 + (9*pow(10, i-2)-d[i-1])*(i-1);
        }

        int sum = 0;
        for (int i = 0; i < n+1; ++i)
        {
            sum += d[i];
        }
        return pow(10, n) - sum;
    }
};
int main(int argc, char *argv[])
{
	int n = 2;
	Solution sol;
	cout<<"ans is:"<<sol.countNumbersWithUniqueDigits(n)<<endl;
	return 0;
}

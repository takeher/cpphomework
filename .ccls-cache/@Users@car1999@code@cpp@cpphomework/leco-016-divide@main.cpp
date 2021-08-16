#include<iostream>
 using namespace std;
 class Solution {
public:
    int divide(int dividend, int divisor) {
	int ans;
	if(!divisor){ans = 2147483647;return ans;}
	if(dividend == -2147483648){if(divisor == -1){return 2147483647;}}
	ans = dividend/divisor;
	return ans;
    }
};
int main(int argc, char *argv[])
{
	int dividend = 10;
	int divisor = 3;
	Solution sol;
	int ans = sol.divide(dividend, divisor);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}
/*


*/

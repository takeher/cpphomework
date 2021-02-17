#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    double quickMul(double x, long long N) {
        double ans = 1.0;
        double x_contribute = x;
        while (N > 0) {
            if (N % 2 == 1) {
                ans *= x_contribute;
            }
            x_contribute *= x_contribute;
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

int main(int argc, char *argv[])
{
	double x = 1024.0;
	int n = 10;
	Solution sol;
	double ans = sol.myPow(x, n);
	cout<<"pow("<<x<<","<<n<<") = "<<ans<<endl;
	return 0;
}

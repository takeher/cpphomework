#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    int z;
    while (y!=0)
    {
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        if (x == 0 || y == 0) {
            return z == 0 || x + y == z;
        }
        return z % gcd(x, y) == 0;
    }
};
int main(int argc, char *argv[])
{
	Solution sol;
	cout<<"ans is:"<<sol.canMeasureWater(3, 5, 4)<<endl;
	return 0;
}

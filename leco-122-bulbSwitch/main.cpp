#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
int main(int argc, char *argv[])
{
	int n = 5;
	Solution sol;
	cout<<"ans is:"<<sol.bulbSwitch(n)<<endl;
	return 0;
}

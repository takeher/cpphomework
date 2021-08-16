#include<bits/stdc++.h>
using namespace std;
int rand7(){
	unsigned seed = 7;
	srand(seed);
	return rand()%seed+1;
}
class Solution {
public:
    int rand10() {
        int a, b, idx;
        while (true) {
            a = rand7();
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 40)
                return 1 + (idx - 1) % 10;
            a = idx - 40;
            b = rand7();
            // get uniform dist from 1 - 63
            idx = b + (a - 1) * 7;
            if (idx <= 60)
                return 1 + (idx - 1) % 10;
            a = idx - 60;
            b = rand7();
            // get uniform dist from 1 - 21
            idx = b + (a - 1) * 7;
            if (idx <= 20)
                return 1 + (idx - 1) % 10;
        }
    }
};
int main(int argc, char *argv[])
{
	Solution sol;
	cout<<"ans is:"<<sol.rand10()<<endl;
	return 0;
}

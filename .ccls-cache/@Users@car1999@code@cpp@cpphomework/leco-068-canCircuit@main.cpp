#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};
int main(int argc, char *argv[])
{
	vector<int> gas {1,2,3,4,5};
	vector<int> cost {3,4,5,1,2};
	Solution sol;
	int ans = sol.canCompleteCircuit(gas, cost);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

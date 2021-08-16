#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        for (int i = 1; i < n; ++i) {
            tie(f0, f1, f2) = make_tuple(max(f0, f2 - prices[i]), f0 + prices[i], max(f1, f2));
        }

        return max(f1, f2);
    }
};
int main(int argc, char *argv[])
{
	vector<int> prices {1,2,3,0,2};
	Solution sol;
	cout<<"ans is:"<<sol.maxProfit(prices)<<endl;
	return 0;
}

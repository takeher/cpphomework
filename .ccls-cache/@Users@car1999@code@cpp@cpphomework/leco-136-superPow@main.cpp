#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const long M = 1337;
    vector<long> findLoop(int a) {
        vector<long> res;
        vector<bool> r(M, 0);
        long long k = a % M;
        while (!r[k]) {
            res.push_back(k);
            r[k] = true;
            k *= (long) a;
            k %= (long) M;
        }
        res.push_back(k);
        return res;
    }
    int superPow(int a, vector<int>& b) {
        auto nums = findLoop(a);
        // 寻找到循环的入口 + 1
        int k = find(nums.begin(), nums.end(), nums.back()) - nums.begin() + 1;
        int l = nums.size() - k;
        int n = 0;
        bool in_loop = false; // 是否进入循环
        int u = 1;
        for (int i = b.size() - 1; i >= 0; --i) {
            n += b[i] * u;
            if (!in_loop && n > k) {
                n = n - k;
                in_loop = true;
            }
            u *= 10;
            if (in_loop) {
                u %= l;
                n %= l;
            }
        }
        return nums[n + k - 1];
    }
};
int main(int argc, char *argv[])
{
	int a = 2;
	vector<int> b {1,0};
	Solution sol;
	cout<<"ans is:"<<sol.superPow(a, b)<<endl;
	return 0;
}

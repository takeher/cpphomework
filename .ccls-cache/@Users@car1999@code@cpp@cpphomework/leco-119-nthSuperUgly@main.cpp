#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int* nums = new int[n];
        memset(nums, 0, sizeof(int)*n);
        nums[0] = 1;

        int np = primes.size();
        // primes的对应nums的序号
        int* p = new int[np];
        memset(p, 0, sizeof(int)*np);

        // 从1~n-1开始遍历
        for (int i = 1; i < n; ++i)
        {
            // 或许所有质数结果里最小的数作为下一个数字
            int currMin = INT_MAX;
            for (int j = 0; j < np; ++j)
            {
                currMin = min(currMin, nums[p[j]]*primes[j]);
            }

            nums[i] = currMin;

            // 判断是否和自己结果相等，是则序号+1
            for (int j = 0; j < np; ++j)
            {
                if (currMin == nums[p[j]]*primes[j])
                {
                    ++p[j];
                }
            }
        }

        return nums[n-1];
    }
};
int main(int argc, char *argv[])
{
	int n = 12;
	vector<int> primes {2,7,13,19};
	Solution sol;
	cout<<"ans is:"<<sol.nthSuperUglyNumber(n, primes)<<endl;
	return 0;
}

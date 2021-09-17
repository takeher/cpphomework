#include <iostream>
#include <unordered_map>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> digits(int n) {
        vector<int> res;
        while (n > 0) {
            res.push_back(n % 10);
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int maximumSwap(int num) {
        vector<int> nums = digits(num);
        int i = 1;
        int N = nums.size();
        while (i < N && nums[i] <= nums[i - 1]) ++i;
        if (i == N) return num;

        int max_val = nums[i];
        int max_ind = i;
        for (; i < N; ++i) {
            if (nums[i] >= max_val) {
                max_val = nums[i];
                max_ind = i;
            }
        }
        for (i = 0; i < N; ++i) {
            if (nums[i] < max_val) {
                break;
            }
        }
        swap(nums[i], nums[max_ind]);
        int res = 0;
        for (auto x : nums) {
            res = 10 * res + x;
        }
        return res;
    }
};
int main()
{
    cout<<"ans is:"<<(new Solution())->maximumSwap(2736)<<endl;
    return 0;
}

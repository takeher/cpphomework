#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPairs(const vector<int>& nums, int k) {
        // 保存满足条件的数字
        unordered_set<int> set1;
        // 保存存在的数字
        unordered_set<int> set2;
        for (int x : nums)
        {
            if (set2.find(x-k) != set2.end())
            {
                set1.insert(x-k);
            }
            if (set2.find(x+k) != set2.end())
            {
                set1.insert(x);
            }
            set2.insert(x);
        }
        return set1.size();
    }
};
int main(int argc, char *argv[])
{
	cout<<"ans is:"<<(new Solution())->findPairs((vector<int>){3,1,4,1,5}, 2)<<endl;
	return 0;
}

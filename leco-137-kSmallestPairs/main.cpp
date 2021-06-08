#include<bits/stdc++.h>
using namespace std;
// 定义的类用于比较使用
struct item
{
    int sum;
    int x;
    int y;
    item(int sum, int x,int y) : sum(sum),x(x),y(y) {}
};

bool operator< (item a, item b)
{
    return a.sum > b.sum;
}

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<item> q;
        for (int i : nums1)
        {
            for (int j : nums2)
            {
                q.emplace(i+j, i, j);
            }
        }

        vector<vector<int>> res;
        while (k-- > 0 && !q.empty())
        {
            const item& curr = q.top();
            res.push_back({curr.x, curr.y});
            q.pop();
        }
        return res;
    }
};
int main(int argc, char *argv[])
{
	vector<int> nums1 {1,7,11};
	vector<int> nums2 {2,4, 6};
	Solution sol;
	auto ans = sol.kSmallestPairs(nums1, nums2, 3);
	cout<<"ans is:"<<endl;
	for(int i = 0;i < ans.size();++i){
		for(int j = 0;j < ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

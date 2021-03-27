#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for(int i = triangle.size() - 2; i >= 0; i --)
            for(int j = 0; j <= i; j ++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        return dp[0];
    }
};
int main(int argc, char *argv[])
{
	vector<int> v1 {2};
	vector<int> v2 {3,4};
	vector<int> v3 {6,5,7};
	vector<int> v4 {4,1,8,3};
	vector<vector<int>> triangle;
	triangle.push_back(v1);
	triangle.push_back(v2);
	triangle.push_back(v3);
	triangle.push_back(v4);
	Solution sol;
	auto ans = sol.minimumTotal(triangle);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

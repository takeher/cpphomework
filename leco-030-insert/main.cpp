#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
	vector<int> newInterval {2,5};
	vector<vector<int>> intervals;
	vector<int> r1{1,3};intervals.push_back(r1);
	vector<int> r2{6,9};intervals.push_back(r2);
	Solution sol;
	auto ans = sol.insert(intervals, newInterval);
	cout<<"ans is:"<<endl;
	for(int i = 0;i < ans.size();++i){
		for(int j = 0;j < ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

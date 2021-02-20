#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
int main(int argc, char *argv[])
{
	vector<vector<int>> intervals;
	vector<int> r1 {1,3};intervals.push_back(r1);
	vector<int> r2 {2,6};intervals.push_back(r2);
	vector<int> r3 {8,10};intervals.push_back(r3);
	vector<int> r4 {15,18};intervals.push_back(r4);
	Solution sol;
	auto ans = sol.merge(intervals);
	cout<<"ans is:"<<endl;
	for(int i = 0;i < ans.size();++i){
		for(int j = 0;j < ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}


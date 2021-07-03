#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
        });

        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= right) {
                ++ans;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};
int main(int argc, char *argv[])
{
	//[1,2], [2,3], [3,4], [1,3]
	vector<vector<int>> intervals;
	vector<int> i1 {1,2};
	vector<int> i2 {2,3};
	vector<int> i3 {3,4};
	vector<int> i4 {1,3};
	intervals.push_back(i1);
	intervals.push_back(i2);
	intervals.push_back(i3);
	intervals.push_back(i4);
	Solution sol;
	cout<<"ans is:"<<sol.eraseOverlapIntervals(intervals)<<endl;
	return 0;
}

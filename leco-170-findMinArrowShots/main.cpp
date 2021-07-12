#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
        });
        int pos = points[0][1];
        int ans = 1;
        for (const vector<int>& balloon: points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++ans;
            }
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
	//points = [[10,16],[2,8],[1,6],[7,12]]
	vector<vector<int>> points;
	vector<int> p1 {10,16};points.push_back(p1);
	vector<int> p2 { 2, 8};points.push_back(p2);
	vector<int> p3 { 1, 6};points.push_back(p3);
	vector<int> p4 { 7,12};points.push_back(p4);
	Solution sol;
	cout<<"ans is:"<<sol.findMinArrowShots(points)<<endl;
	return 0;
}

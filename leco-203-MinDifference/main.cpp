#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinDifference(const vector<string>& timePoints) {
        int n = timePoints.size();
        int times[n];
        for (int i = 0; i < n; ++i)
        {
            // times[i] = stoi(timePoints[i].substr(0,2))*60 + stoi(timePoints[i].substr(3,2));
            times[i] = ((timePoints[i][0]-'0')*10 + (timePoints[i][1]-'0'))*60 +
                    (timePoints[i][3]-'0')*10 + (timePoints[i][4]-'0');
        }

        sort(times, times+n);
        int res = INT_MAX;
        for (int i = 0; i < n-1; ++i)
        {
            res = min(res, times[i+1]-times[i]);
        }
        // 最后一个还要和第一个比较
        res = min(res, 24*60+times[0] - times[n-1]);
        return res;
    }
};
int main(int argc, char *argv[])
{
	cout<<"ans is:"<<(new Solution())->findMinDifference(vector<string> {"23:59","00:00"})<<endl;
	return 0;
}

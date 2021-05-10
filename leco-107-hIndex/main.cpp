#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i = 0;
        while(i < citations.size() && citations[citations.size() - 1 - i] > i) i++;
        return i;
    }
};
int main(int argc, char *argv[])
{
	vector<int> citations {3,0,6,1,5};
	Solution sol;
	cout<<"ans is:"<<sol.hIndex(citations)<<endl;
	return 0;
}

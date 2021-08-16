#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0,r=citations.size();
        while(l<r){
            int mid=((l+r+1)>>1);
            if(citations[citations.size()-mid]>=mid) l=mid;
            else r=mid-1;
        }
        return r;
    }
};
int main(int argc, char *argv[])
{
	vector<int> citations {0,1,3,5,6};
	Solution sol;
	cout<<"ans is:"<<sol.hIndex(citations)<<endl;
	return 0;
}

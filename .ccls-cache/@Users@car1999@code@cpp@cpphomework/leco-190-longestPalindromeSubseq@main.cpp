#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dpArr(s.size(),vector<int>(s.size(),-1));
        return dp(dpArr,s,0,s.size()-1);
    }
    int dp(vector<vector<int>>& dpArr,string& s,int start, int end){
        if(dpArr[start][end]>0) return dpArr[start][end];
        if(start>end) return 0;
        if(start==end) return dpArr[start][end]=1;
        return dpArr[start][end]=(s[start]==s[end])?2+dp(dpArr,s,start+1,end-1):max(dp(dpArr,s,start,end-1),dp(dpArr,s,start+1,end));
    }
};
int main(int argc, char *argv[])
{
	string s = "bbbab";
	Solution sol;
	cout<<"ans is:"<<sol.longestPalindromeSubseq(s)<<endl;
	return 0;
}

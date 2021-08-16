#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> res;
        int n = s.length();
        if(n == 0)
            return res;
        for(int i = 0; i <= n-10; i++)
        {
            string t = s.substr(i, 10);
            if(mp.count(t) && mp[t] == 1)
                res.push_back(t);
            mp[t]++;
        }
        return res;
    }
};
int main(int argc, char *argv[])
{
	string s =  "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution sol;
	auto ans = sol.findRepeatedDnaSequences(s);
	cout<<"ans is:"<<endl;
	for(int i = 0;i < ans.size();++i){
		cout<<ans[i]<<endl;
	}
	return 0;
}

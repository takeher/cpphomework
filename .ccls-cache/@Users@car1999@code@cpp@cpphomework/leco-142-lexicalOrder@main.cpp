#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> temp;
        while(n)
        {
            temp.push_back(n);
            n--;
        }
        sort(temp.begin(),temp.end(),[](int& a ,int& b){return to_string(a)<to_string(b);});
        return temp;
    }
};
int main(int argc, char *argv[])
{
	Solution sol;
	auto ans = sol.lexicalOrder(13);
	cout<<"ans is:";
	for(int i = 0;i < ans.size();++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}

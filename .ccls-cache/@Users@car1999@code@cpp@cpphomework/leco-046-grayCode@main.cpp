#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<int> grayCode(int n) {
        int x=0;
        core(n, x);
        return res;
    }
    void core(int n, int &x){
        res.push_back(x);

        for(int i=1; i<=n; i++){
            x^=(1<<(i-1));
            core(i-1, x);
        }
    }
};
int main(int argc, char *argv[])
{
	int n = 2;
	Solution sol;
	auto ans = sol.grayCode(n);
	cout<<"ans is:";
	for (int i = 0; i < ans.size(); ++i) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}

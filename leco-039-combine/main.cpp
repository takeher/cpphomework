#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> now {0};
        function<void(void)> dfs = [&] {
            if (now.size() == k + 1) {
                ret.emplace_back(next(begin(now)), end(now));
            } else {
                for (int i = now.back() + 1; i + k - now.size() != n + 1; ++i) {
                    now.push_back(i);
                    dfs();
                    now.pop_back();
                }
            }
        };
        dfs();
        return ret;
    }
};
int main(int argc, char *argv[])
{
	int n = 5;
	int k = 3;
	Solution sol;
	auto ans = sol.combine(n,k);
	cout<<"ans is:"<<endl;
	for(int i = 0;i < ans.size();++i){
		for(int j = 0;j < ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

    vector<string> stk;

    void dfs(const string& curr) {
        while (vec.count(curr) && vec[curr].size() > 0) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& it : tickets) {
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK");

        reverse(stk.begin(), stk.end());
        return stk;
    }
};
int main(int argc, char *argv[])
{
	//[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
	vector<vector<string>> tickets;
	vector<string> t1 {"MUC","LHR"};
	vector<string> t2 {"JFK","MUC"};
	vector<string> t3 {"SFO","SJC"};
	vector<string> t4 {"LHR","SFO"};
	tickets.push_back(t1);
	tickets.push_back(t2);
	tickets.push_back(t3);
	tickets.push_back(t4);
	Solution sol;
	auto ans = sol.findItinerary(tickets);
	cout<<"ans is:";
	for(int i = 0;i < ans.size();++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}

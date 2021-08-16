#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        });
        vector<vector<int>> ans;
        for (const vector<int>& person: people) {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
	//people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
	vector<vector<int>> people;
	vector<int> p1 {7,0};
	vector<int> p2 {4,4};
	vector<int> p3 {7,1};
	vector<int> p4 {5,0};
	vector<int> p5 {6,1};
	vector<int> p6 {5,2};
	people.push_back(p1);
	people.push_back(p2);
	people.push_back(p3);
	people.push_back(p4);
	people.push_back(p5);
	people.push_back(p6);
	Solution sol;
	auto ans = sol.reconstructQueue(people);
	cout<<"ans is:"<<endl;
	for(int i = 0;i < ans.size();++i){
		for(int j = 0;j < ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};
int main(int argc, char *argv[])
{
	int numCourses = 2;
	vector<vector<int>> prerequisites;
	vector<int> r1 = {1,0};
	vector<int> r2 = {0,1};
	prerequisites.push_back(r1);
	prerequisites.push_back(r2);
	Solution sol;
	bool ans = sol.canFinish(numCourses, prerequisites);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

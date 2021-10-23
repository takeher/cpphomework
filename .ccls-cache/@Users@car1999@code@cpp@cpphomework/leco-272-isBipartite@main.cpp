#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    vector<int> color;

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, UNCOLORED);
        for (int i = 0; i < n; ++i) {
            if (color[i] == UNCOLORED) {
                queue<int> q;
                q.push(i);
                color[i] = RED;
                while (!q.empty()) {
                    int node = q.front();
                    int cNei = (color[node] == RED ? GREEN : RED);
                    q.pop();
                    for (int neighbor: graph[node]) {
                        if (color[neighbor] == UNCOLORED) {
                            q.push(neighbor);
                            color[neighbor] = cNei;
                        }
                        else if (color[neighbor] != cNei) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
// graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
int main(){
  auto graph = vector<vector<int>> {
    vector<int>{1, 2, 3}, vector<int>{0,2}, vector<int>{0,1,3}, vector<int>{0,2}};
  cout<<"ans is:"<<(new Solution())->isBipartite(graph)<<endl;
    return 0;
}

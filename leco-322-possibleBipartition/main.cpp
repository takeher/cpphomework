#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> graph;
    vector<int> color;
public:
    /* 未染色为0, 染色的分成2种, 1/-1 */
    bool dfs(int u, int c) {
        color[u] = c;
        for (auto v : graph[u]) {
            if (color[v] == c) {
                return false;
            }
            if (color[v] == 0 && !dfs(v, -c)) {
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        graph = vector<vector<int>>(n);
        color = vector<int>(n);

        /* 建立邻接表 */
        for (auto dislike : dislikes) {
            int u = dislike[0] - 1;
            int v = dislike[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        /* 对每个节点判断, 是否为二分图 */
        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && !dfs(i, 1)) {
                return false;
            }
        }
        return true;
    }
};
int main(){
  cout<<"ans is:";
  auto dislikes = vector<vector<int>> {vector<int> {1,2},vector<int> {1,3},vector<int>{2,4}};
  cout<<(new Solution())->possibleBipartition(4, dislikes)<<endl;
  return 0;
}

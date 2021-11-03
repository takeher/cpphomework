#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int length = graph.size();
    vector<vector<int>> dgraph(length);
    vector<int> inDegree(length);
    vector<int> res;
    //将图逆序
    for (unsigned i = 0; i < length; ++i) {
      for (auto x : graph[i]) {
        dgraph[x].push_back(i);
      }
      inDegree[i] = graph[i].size();
    }
    //将起始入度为0的节点存在队列中
    queue<int> q;
    for (unsigned i = 0; i < length; ++i) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }
    //拓扑排序
    while (!q.empty()) {
      int cur = q.front();
      for (auto next : dgraph[cur]) {
        inDegree[next]--;
        if (inDegree[next] == 0) {
          q.push(next);
          // res.push_back(next);
        }
      }
      q.pop();
    }
    //遍历入度数组，入度为0就是答案之一
    for (int i = 0; i < length; i++) {
      if (inDegree[i] == 0)
        res.push_back(i);
    }
    return res;
  }
};
int main(){
  cout<<"ans is:";
  // graph = [[1,2],[2,3],[5],[0],[5],[],[]]
  auto graph = vector<vector<int>> {
    vector<int> {1,2},
    vector<int> {2,3},
    vector<int> {5},
    vector<int> {0},
    vector<int> {5},
    vector<int> {},
    vector<int> {}
  };
  auto ans = (new Solution())->eventualSafeNodes(graph);
  for_each(ans.begin(), ans.end(), [](int x){cout<<x<<" ";});
  return 0;
}

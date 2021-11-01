#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> ans;

    auto dfs = [&](auto &&dfs, vector<int> &path, int i) {
      if (i == n - 1)
        return ans.push_back(path);
      for (auto &nxt : graph[i]) {
        path.push_back(nxt);
        dfs(dfs, path, nxt);
        path.pop_back();
      }

      return;
    };

    vector<int> path{0};
    dfs(dfs, path, 0);
    return ans;
  }
};
int main(){
  // graph = [[1,2],[3],[3],[]]
  auto graph = vector<vector<int>> {
    vector<int> {1,2},
    vector<int> {3},
    vector<int> {3},
    vector<int> {}
  };
  auto ans = (new Solution())->allPathsSourceTarget(graph);
  cout<<"ans is:"<<endl;
  for_each(ans.begin(), ans.end(), [](vector<int> &a){
    cout<<"[";
    for_each(a.begin(), a.end(), [](int x){cout<<x<<" ";});
    cout<<"]"<<endl;
  });
  return 0;
}

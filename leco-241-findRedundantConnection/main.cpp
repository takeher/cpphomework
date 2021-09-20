#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodesCount = edges.size();
        vector<int> parent(nodesCount + 1);
        for (int i = 1; i <= nodesCount; ++i) {
            parent[i] = i;
        }
        for (auto& edge: edges) {
            int node1 = edge[0], node2 = edge[1];
            if (Find(parent, node1) != Find(parent, node2)) {
                Union(parent, node1, node2);
            } else {
                return edge;
            }
        }
        return vector<int>{};
    }
};
int main(){
  vector<vector<int>> edges {
    vector<int> {1,2},
    vector<int> {1,3},
    vector<int> {2,3},
  };
  cout<<"ans is:";
  auto ans = (new Solution())->findRedundantConnection(edges);
  for_each(ans.begin(), ans.end(), [](int x){cout<<x<<" ";});
  return 0;
}

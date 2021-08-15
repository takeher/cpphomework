#include <bits/stdc++.h>
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

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = isConnected.size();
        vector<int> parent(provinces);
        for (int i = 0; i < provinces; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < provinces; i++) {
            for (int j = i + 1; j < provinces; j++) {
                if (isConnected[i][j] == 1) {
                    Union(parent, i, j);
                }
            }
        }
        int circles = 0;
        for (int i = 0; i < provinces; i++) {
            if (parent[i] == i) {
                circles++;
            }
        }
        return circles;
    }
};
int main() {
  vector<vector<int> > isconnected;
  vector<int> i1 {1, 1, 0};
  isconnected.push_back(i1);
  vector<int> i2 {1, 1, 0};
  isconnected.push_back(i2);
  vector<int> i3 {1, 1, 0};
  isconnected.push_back(i3);
  cout<<"ans is:"<<(new Solution())->findCircleNum(isconnected)<<endl;
  return 0;
}

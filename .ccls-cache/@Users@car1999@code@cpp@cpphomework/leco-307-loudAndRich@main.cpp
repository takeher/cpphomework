#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    int N = quiet.size();
    vector<vector<int>> adj(N);
    queue<int> q;
    vector<int> answer(N);
    for (int i = 0; i < N; i++)
      answer[i] = i;
    int *nupo = new int[N];
    memset(nupo, 0, sizeof(int) * N);
    for (vector<int> &c : richer) {
      int from = c[0];
      int to = c[1];
      adj[from].push_back(to);
      nupo[to]++;
    }
    for (int i = 0; i < N; i++) {
      if (nupo[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int p = q.front();
      q.pop();
      for (int i : adj[p]) {
        nupo[i]--;
        if (quiet[answer[i]] > quiet[answer[p]])
          answer[i] = answer[p];
        if (nupo[i] == 0)
          q.push(i);
      }
    }
    return answer;
  }
};
int main(){
  //[[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]
  auto richer = vector<vector<int>>{vector<int>{1, 0}, vector<int>{2, 1}, vector<int>{3, 1}, vector<int>{3, 7},  vector<int>{4, 3}, vector<int>{5, 3},  vector<int>{6, 3}};
  auto quiet = vector<int>{3, 2, 5, 4, 6, 1, 7, 0};
  auto ans = (new Solution())->loudAndRich(richer, quiet);
  cout<<"ans is:";
  for_each(ans.begin(), ans.end(), [](int x){cout<<x<<" ";});
  return 0;
}


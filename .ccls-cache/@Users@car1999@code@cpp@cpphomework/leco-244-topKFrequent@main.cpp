#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> cnt;
    for (auto &word : words) {
      cnt[word]++;
    }
    auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
      return a.second == b.second ? a.first < b.first : a.second > b.second;
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)>
        que(cmp);
    for (auto &it : cnt) {
      que.emplace(it);
      if (que.size() > k) {
        que.pop();
      }
    }
    vector<string> ret(k);
    for (int i = k - 1; i >= 0; i--) {
      ret[i] = que.top().first;
      que.pop();
    }
    return ret;
  }
};
int main(){
  vector<string> words { "i", "love", "leetcode", "i", "love", "coding" };
  auto ans = (new Solution())->topKFrequent(words, 2);
  cout<<"ans is:";
  for_each(ans.begin(), ans.end(),[](string x){cout<<x<<" ";});
  return 0;
}

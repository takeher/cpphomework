#include<bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
public:
  vector<int> tops;
  vector<int> times;

  TopVotedCandidate(const vector<int> &persons, const vector<int> &times) {
    unordered_map<int, int> voteCounts;
    voteCounts[-1] = -1;
    int top = -1;
    for (auto &p : persons) {
      voteCounts[p]++;
      if (voteCounts[p] >= voteCounts[top]) {
        top = p;
      }
      tops.emplace_back(top);
    }
    this->times = times;
  }

  int q(int t) {
    int pos = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
    return tops[pos];
  }
};
int main(){
  TopVotedCandidate *obj = new TopVotedCandidate(
      vector<int>{0, 1, 1, 0, 0, 1, 0}, vector<int>{0, 5, 10, 15, 20, 25, 30});
  cout<<"ans is:"<<obj->q(3)<<endl;
  return 0;
}

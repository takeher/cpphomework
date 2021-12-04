#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lenLongestFibSubseq(const vector<int> &A) {
    int N = A.size();
    unordered_map<int, int> index;
    for (int i = 0; i < N; ++i)
      index[A[i]] = i;

    unordered_map<int, int> longest;
    int ans = 0;
    for (int k = 0; k < N; ++k)
      for (int j = 0; j < k; ++j) {
        if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
          int i = index[A[k] - A[j]];
          longest[j * N + k] = longest[i * N + j] + 1;
          ans = max(ans, longest[j * N + k] + 2);
        }
      }

    return ans >= 3 ? ans : 0;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->lenLongestFibSubseq(vector<int> {1,2,3,4,5,6,7,8})<<endl;
  return 0;
}

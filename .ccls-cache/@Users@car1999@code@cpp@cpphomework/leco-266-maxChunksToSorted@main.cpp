#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxChunksToSorted(const vector<int> &arr) {
    stack<int> maxStk;
    maxStk.push(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] < maxStk.top()) {
        int maxNum = maxStk.top();
        while (!maxStk.empty() && maxStk.top() > arr[i])
          maxStk.pop();
        maxStk.push(maxNum);
      } else
        maxStk.push(arr[i]);
    }
    return maxStk.size();
  }
};
int main(){
  cout << "ans is"
       << (new Solution())->maxChunksToSorted(vector<int>{4,3,2,1,0})<<endl;
  return 0;
}

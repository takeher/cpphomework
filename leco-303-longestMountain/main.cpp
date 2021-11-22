#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestMountain(const vector<int> &arr) {
    int size = arr.size();
    vector<int> increase(size, 1);
    vector<int> decrease(size, 1);
    vector<int> dp(size, 0);
    for (int i = 1; i < size; ++i) {
      if (arr[i] > arr[i - 1]) {
        increase[i] = increase[i - 1] + 1;
      }
    }
    for (int i = size - 2; i >= 0; --i) {
      if (arr[i] > arr[i + 1]) {
        decrease[i] = decrease[i + 1] + 1;
      }
    }
    for (int i = 0; i < size; ++i) {
      if (increase[i] != 1 && decrease[i] != 1) {
        int len = increase[i] + decrease[i] - 1;
        if (len > 1) {
          dp[i] = len;
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->longestMountain(vector<int> {2,1,4,7,3,2,5})<<endl;
  return 0;
}

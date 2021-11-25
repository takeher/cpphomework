#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string shiftingLetters(string s, const vector<int> &shifts) {
    int n = shifts.size();
    vector<long> everyCharShiift(n, 0);
    everyCharShiift[n - 1] = shifts[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      everyCharShiift[i] = (everyCharShiift[i + 1] + shifts[i]) % 26;
    }
    for (int i = 0; i < n; i++) {
      char &c = s[i];
      if (c + everyCharShiift[i] % 26 > 'z')
        c = c + everyCharShiift[i] % 26 - 26;
      else
        c = c + everyCharShiift[i] % 26;
    }
    return s;
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->shiftingLetters("abc", vector<int> {3,5,9})<<endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int scoreOfParentheses(string S) {
    stack<int> s;
    // 考虑前面提到2次弹出，所以默认先插入一个0
    //  对结果无影响，同时无需考虑边缘情况去判断是否可以弹两次
    s.push(0);

    for (char c : S) {
      if (c == '(') {
        // 默认分数为0
        s.push(0);
      } else {
        int s1 = s.top();
        s.pop();
        int s2 = s.top();
        s.pop();
        // 考虑当前 分数*2 然后再 加上上一个 分数之和
        s.push(max(1, 2 * s1) + s2);
      }
    }

    return s.top();
  }
};
int main(){
  cout<<"ans is:"<<(new Solution())->scoreOfParentheses("()")<<endl;
  return 0;
}

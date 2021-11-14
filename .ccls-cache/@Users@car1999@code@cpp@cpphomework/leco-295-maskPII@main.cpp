#include <bits/stdc++.h>
using namespace std;



class Solution {
private:
    void ToLower(string& s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            s[i] = tolower(s[i]);
        }
    }
public:
    string maskPII(string s) {
        int index = s.find('@');
        bool isEmail = index != s.npos;

        if (isEmail)
        {
            // 前半部分是 首字母小写+“*****” 后面字母小写
            // 后半部分是 变为小写即可
            string rest = s.substr(index-1);
            ToLower(rest);
            return string{(char)tolower(s[0])} + "*****" + rest;
        }
        else
        {
            // 电话号码情况
            // 替换所有非数字的情况
            string curr = regex_replace(s, regex("\\D+"), "");
            // cout << curr << endl;
            // 对于大于10的需要考虑+和** 和后半部分就是 *** +四个数字
            return (curr.size() > 10 ? "+" + string(curr.size()-10, '*') + "-" : "") + 
                "***-***-" + curr.substr(curr.size()-4);
        }
    }
};
int main(){
  cout << "ans is:" << (new Solution())->maskPII("LeetCode@LeetCode.com")
       << endl;
  return 0;
}

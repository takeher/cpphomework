#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        if(dfs(0, ans, S))
            return ans;
        else
            return {};
    }

    //pos为字符串位置  ans为答案的int数组  s为原来的字符串
    bool dfs(int pos, vector<int> &ans, const string &s){
        //字符串分割完毕
        if(pos == s.length()){
            //数组大小 大于等于3才符合要求
            if(ans.size() >= 3)
                return true;
            else
                return false;
        }
        //为0
        if(s[pos] == '0'){
            if(ans.size() >= 2 && 0 != ans[ans.size() - 1] + ans[ans.size() - 2])
                return false;
            //递归处理就是0的情况
            ans.push_back(0);
            if(dfs(pos + 1, ans, s))
                return true;
            ans.pop_back();
            //否则返回false，题目要求不能有前导0
            return false;
        }
        //记录分割子串的数字
        long long tmp = 0;
        for(int i = pos; i < s.length(); i ++){
            tmp = tmp * 10 + s[i] - '0';
            //大于int，则返回false
            if(tmp > INT_MAX)
                return false;
            //不满足斐波那契条件，跳过
            if(ans.size() >= 2 && tmp != (long long)ans[ans.size() - 1] + ans[ans.size() - 2])
                continue;
            //递归处理
            ans.push_back(tmp);
            if(dfs(i + 1, ans, s))
                return true;
            ans.pop_back();
        }
        return false;
    }
};
int main(){
  cout<<"ans is:";
  auto ans  = (new Solution())->splitIntoFibonacci("123456579");
  for_each(ans.begin(), ans.end(), [](int x){cout<<x<<" ";});
  return 0;
}

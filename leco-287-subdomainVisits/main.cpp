#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    vector<string> Split(const string& s, char c)
    {
        vector<string> res;
        stringstream ss(s);
        string curr;
        while(std::getline(ss, curr, c))
        {
            // cout << "[" <<  curr << "]" << endl;
            res.push_back(curr);
        }
        return res;
    }

public:
    vector<string> subdomainVisits(const vector<string>& cpdomains) {
        // 保存数量映射的哈希表
        unordered_map<string, int> str2cnt;

        // 遍历去拆分字符串
        for (const string& cp : cpdomains)
        {
            vector<string> cc = Split(cp, ' ');
            vector<string> s = Split(cc[1], '.');
            int cnt = stoi(cc[0]);
            // 从后往前去构建字符串数组
            string curr = "";
            for (int i = s.size()-1; i >= 0; --i)
            {
                curr = s[i] + (curr.empty() ? "" : ".") + curr;
                str2cnt[curr] += cnt;
            }
        }

        vector<string> res;
        for (auto iter = str2cnt.begin(); iter != str2cnt.end(); ++iter)
        {
            res.push_back(to_string(iter->second) + " " + iter->first);
        }

        return res;
    }
};
int main(){
  cout << "ans is:";
  auto ans = (new Solution())->subdomainVisits(vector<string>{"9001 discuss.leetcode.com"});
  for_each(ans.begin(), ans.end(), [](string s){cout<<s<<" ";});
  return 0;
}

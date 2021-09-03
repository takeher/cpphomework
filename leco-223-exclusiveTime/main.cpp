#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // 函数拆分出来字符串
    vector<string> Split(string& str)
    {
        vector<string> res;
        stringstream ss(str);
        string curr;
        while(getline(ss, curr, ':'))
        {
            res.push_back(curr);
        }
        return res;
    }

public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> s;
        vector<string> curr = Split(logs[0]);
        s.push(stoi(curr[0]));
        // 上一个结束的点
        int prev = stoi(curr[2]);
        int i = 1;
        int numLogs = logs.size();
        while (i < numLogs)
        {
            curr = Split(logs[i]);
            if (curr[1] == "start")
            {
                int pos = stoi(curr[2]);
                if (!s.empty())
                {
                    res[s.top()] += pos - prev;
                }
                s.push(stoi(curr[0]));
                prev = pos;
            }
            else
            {
                // 这里需要+1，因为s.top()也是自己
                int pos = stoi(curr[2]);
                res[s.top()] += pos - prev + 1;
                s.pop();
                // 更新到下一个位置，所以+1
                prev = pos + 1;
            }
            ++i;
        }

        return res;
    }
};
int main(){
  vector<string> logs { "0:start:0", "1:start:2", "1:end:5", "0:end:6" };
  auto ans = (new Solution())->exclusiveTime(2, logs);
  cout<<"ans is:";
  for_each(ans.begin(), ans.end(), [](int x){cout<<x<<" ";});
  cout<<endl;
  return 0;
}

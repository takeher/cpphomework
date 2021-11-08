#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 对于特定范围s找到各种可能的字符串数组
    vector<string> Helper(const string& s, int start, int end)
    {
        vector<string> res;
        int n = s.size();
        int nd = end - start+1;
        // cout << "helper " << s.substr(start, nd) << endl;
        for (int d = 1; d <= nd; ++d)
        {
            // 按照不同d去拆分成两部分
            string l = s.substr(start, d);
            string r = s.substr(start+d, nd-d);
            // cout << l << " [" << r << "]" << endl;
            if ((l.compare(0, 1, "0")!=0 || l == "0") && (r.empty() || r.compare(r.size()-1, 1, "0")!=0))
            {
                res.push_back(l + (d<nd?".":"") + r);
            }
        }

        return res;
    }

public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        s = s.substr(1, s.size()-2);
        // cout << s << endl;
        int n = s.size();
        // 按照长度做拆分成两部分，分别获取可能的结果集合，然后组合在一起
        for (int i = 1; i < n; ++i)
        {
            // cout << "outer " << s.substr(0, i) << " " << s.substr(i, n-i) << endl;
            for (const string& left : Helper(s, 0, i-1))
            {
                for (const string& right : Helper(s, i, n-1))
                {
                    res.push_back("(" + left + ", " + right + ")");
                }
            }
        }
        return res;
    }
};
int main(){
  cout<<"ans is:";
  auto ans = (new Solution())->ambiguousCoordinates("(1,2,3)");
  for_each(ans.begin(), ans.end(), [](string s){cout<<s<<" ";});
  return 0;
}

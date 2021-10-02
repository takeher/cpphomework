#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool isComment = false;
        vector<string> res;
        string curr = "";
        for (string s : source)
        {
            // cout << s << endl;
            int i = 0;
            if (!isComment)
            {
                curr = "";
            }
            int n = s.size();
            while (i < n)
            {
                if (!isComment && i < n-1 && s[i] == '/' && s[i+1] == '*')
                {
                    isComment = true;
                    // 继续找下去,这里实际要+2，但是后面会+1
                    ++i;
                }
                else if (isComment && i < n-1 && s[i] == '*' && s[i+1] == '/')
                {
                    isComment = false;
                    // 继续找下去,这里实际要+2，但是后面会+1
                    ++i;
                }
                else if (!isComment && i < n-1 && s[i] == '/' && s[i+1] == '/')
                {
                    break;
                }
                else if (!isComment)
                {
                    curr += s[i];
                    // cout << curr<< " " << endl;
                }
                ++i;
            }
            if (!isComment && !curr.empty())
            {
                res.push_back(curr);
            }
        }
        return res;
    }
};
int main(){
  vector<string> source {
    "/*Test program */", "int main()", "{ ", "  // variable declaration ",
        "int a, b, c;", "/* This is a test", "   multiline  ",
        "   comment for ", "   testing */", "a = b + c;",
        "}"
  };
  auto ans = (new Solution())->removeComments(source);
  cout<<"ans is:";
  for_each(ans.begin(), ans.end(), [](string str){cout<<str<<" ";});
  return 0;
}

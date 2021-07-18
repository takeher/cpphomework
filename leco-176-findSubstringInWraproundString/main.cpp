#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        int n = p.size();
        // 记录连续的最大长度
        int maxLen = 0;
        for (int i = 0; i < n; ++i)
        {
            // 记得考虑 z->a的情况, 相差
            if ((i > 0) && (p[i]-p[i-1]+26)%26 == 1)
            {
                ++maxLen;
            }
            else
            {
                maxLen = 1;
            }
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], maxLen);
        }
        // 再次求和得到最大值
        int res = 0;
        for (int i = 0; i < 26; ++i)
        {
            res += cnt[i];
        }
        return res;
    }
};
int main(int argc, char *argv[])
{
	string p = "a";
	Solution sol;
	cout<<"ans is:"<<sol.findSubstringInWraproundString(p)<<endl;
	return 0;
}

#include<iostream> 
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	int len = 0, max = 0;
	if(s == ""){return 0;}
	int i = 0,t = 0,c = 1;
	while(i < s.size())
	{
		for(int j = t; j < i; ++j)
		{
			if(s[j] == s[i])
			{
				max = len>max?len:max;
				len = -1;
				i = j;
				t = j + 1;
				c = 0;
				break;

			}
		}
		i++;
		len++;
		if(c){max = len>max?len:max;}
		c = 1;
	}
	return max;
    }
};
int main(int argc, char *argv[])
{
	string s = "abcabcbb";
	Solution sol;
	int max = sol.lengthOfLongestSubstring(s);
	cout<<"max length is:"<< max<<endl;
	return 0;
}
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};
*/

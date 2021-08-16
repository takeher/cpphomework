#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    // src是否包含dst这个子序列
    bool IsSubsequence(string src, string dst)
    {
        int ns = src.size();
        int nt = dst.size();
        int i = 0;
        int j = 0;
        for (; i < ns && j < nt; ++i)
        {
            if (src[i] == dst[j])
            {
                ++j;
            }
        }

        return j == nt;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // 保存最大的结果
        string res = "";
        for (string dst : dictionary)
        {
            if (IsSubsequence(s, dst))
            {
                // 找到更长的 或者 一样长但是字典序更小
                if ((dst.size() > res.size()) || (dst.size() == res.size() && dst < res))
                {
                    res = dst;
                }
            }
        }

        return res;
    }
};
int main(int argc, char *argv[])
{
	string s = "abpcplea";
	vector<string> dictionary {"ale","apple","monkey","plea"};
	Solution sol;
	cout<<"ans is:"<<sol.findLongestWord(s, dictionary)<<endl;
	return 0;
}

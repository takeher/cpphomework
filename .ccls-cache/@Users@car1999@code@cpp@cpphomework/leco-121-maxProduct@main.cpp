#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int* masks = new int[n];
        memset(masks, 0, sizeof(int)*n);
        int* lens = new int[n];
        // 预先计算和长度
        for (int i = 0; i < n; ++i)
        {
            for (char c : words[i])
            {
                masks[i] |= 1 << (c - 'a');
            }
            lens[i] = words[i].size();
        }

        // 保存最大的乘积
        int res = 0;
        // 两层遍历
        int curr = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                curr = lens[i]*lens[j];
                if (curr > res)
                {
                    // cout << curr << " " << i << "," << j << " " << (masks[i] & masks[j]) << endl;
                    if ((masks[i] & masks[j]) == 0)
                    {
                        res = curr;
                    }
                }
            }
        }
        return res;
    }
};
int main(int argc, char *argv[])
{
	vector<string> words;
	//"abcw","baz","foo","bar","xtfn","abcdef"
	words.push_back("abcw");
	words.push_back("baz");
	words.push_back("foo");
	words.push_back("bar");
	words.push_back("xtfn");
	words.push_back("abcdef");
	Solution sol;
	cout<<"ans is:"<<sol.maxProduct(words)<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // 先构建bank的字典，方便快速查找, 如果使用后会删除，避免循环遍历
        unordered_set<string> bankSet;
        for (string& b : bank)
        {
            bankSet.insert(b);
        }
        // 提前判断
        if (bankSet.find(end) == bankSet.end())
        {
            return -1;
        }

        // 可以选择的四个字符
        char replaces[4] = {'A', 'C', 'G', 'T'};

        // 构建初始化的两个头尾集合
        unordered_set<string> heads = {start};
        unordered_set<string> tails = {end};
        // 一个临时变量用于保存当前集合
        unordered_set<string> temp;
        // 次数记录:按照每一层去累加
        int rounds = 0;
        while (!heads.empty() && !tails.empty())
        {
            ++rounds;
            // 取最小的来作为遍历的对象,最小一直在heads里
            if (heads.size() > tails.size())
            {
                swap(heads, tails);
            }

            for (const string& head : heads)
            {
                string curr = head;
                // 遍历每个字符
                int n = curr.size();
                for (int i = 0; i < n; ++i)
                {
                    char old = curr[i];
                    // 替换四种可能性
                    for (int j = 0; j < 4; ++j)
                    {
                        curr[i] = replaces[j];
                        // cout << rounds << " : " << curr << " " << head << endl;
                         // 在尾巴里找到了，则直接返回
                        if (tails.find(curr) != tails.end())
                        {
                            return rounds;
                        }
                        else if (bankSet.find(curr) != bankSet.end())
                        {
                            bankSet.erase(curr);
                            temp.insert(curr);
                        }
                    }
                    // 必不可少的还原字符
                    curr[i] = old;
                }
            }
            // 快速交换赋值给heads
            swap(heads, temp);
            temp.clear();
        }

        // 找不到则返回-1
        return -1;
    }
};
int main(int argc, char *argv[])
{
	auto start = "AACCGGTT";
	auto end =   "AAACGGTA";
	vector<string> bank {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
	Solution sol;
	cout<<"ans is:"<<sol.minMutation(start,	end, bank)<<endl;
	return 0;
}

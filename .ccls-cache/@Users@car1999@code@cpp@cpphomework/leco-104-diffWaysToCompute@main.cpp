#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int n = input.size();
        //size_t offset = 0;
        int num = 0;
        int i = 0;
        while (i < n && isdigit(input[i]))
        {
            num = num*10 + (int)(input[i]-'0');
            ++i;
        }
        if (i == n)
        {
            return {num};
        }
        // cout << num << endl;

        vector<int> res;
        // 这里考虑不会出现在收尾的运算符
        for (int i = 0; i < n; ++i)
        {
            if (input[i] == '+' || input[i] == '*' || input[i] == '-')
            {
                // 分别拆分两部分，得到对应的多种不同的结果
                vector<int> leftRes = diffWaysToCompute(input.substr(0, i));
                vector<int> rightRes = diffWaysToCompute(input.substr(i+1));
                for (int left : leftRes)
                {
                    for (int right : rightRes)
                    {
			//cout << left << input[i] << right << endl;
                        // 按照运算符分别去计算
                        if (input[i] == '+')
                        {
                            res.push_back(left + right);
                        }
                        else if (input[i] == '*')
                        {
                            res.push_back(left * right);
                        }
                        else
                        {
                            res.push_back(left - right);
                        }
                    }
                }
            }
        }
        return res;
    }
};
int main(int argc, char *argv[])
{
	string input = "2-1-1";
	Solution sol;
	auto ans = sol.diffWaysToCompute(input);
	cout<<"ans is:";
	for(int i = 0;i < ans.size();++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}

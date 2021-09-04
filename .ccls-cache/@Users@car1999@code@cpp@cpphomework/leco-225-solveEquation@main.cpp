#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // 按照+，-符号去拆分计算公式
    vector<string> SplitEquation(const string& str)
    {
        vector<string> res;
        string pre = "";
        int n = str.size();
        for (int i = 0; i < n; ++i)
        {
            if (str[i] == '+' || str[i] == '-')
            {
                if (!pre.empty())
                {
                    res.push_back(pre);
                }
                pre = str[i];
            }
            else
            {
                pre += str[i];
            }
        }
        res.push_back(pre);
        return res;
    }

    // 获取x前面的系数: 前缀 或者 1（默认）
    int GetXCoefficent(string& str)
    {
        if (str.size() > 1 && str[str.size()-2] >= '0' && str[str.size()-2] <= '9')
        {
            replace(str.begin(), str.end(), 'x', ' ');
        }
        else
        {
            replace(str.begin(), str.end(), 'x', '1');
        }
        // cout << str << " coff " << stoi(str) << endl;
        return stoi(str);
    }

public:
    string solveEquation(string equation) {
        // 按照等于把字符串拆分两部分
        int n = equation.size();
        int i = equation.find("=");
        auto ls = SplitEquation(equation.substr(0, i));
        auto rs = SplitEquation(equation.substr(i+1, n-i-1));

        // 左右的系数
        int lhs = 0;
        int rhs = 0;
        for (string& s : ls)
        {
            // cout << "ls " << s << endl;
            // 对于左侧： x则直接加在lhs里
            if (s.find('x') != s.npos)
            {
                lhs += GetXCoefficent(s);
            }
            else
            {
                rhs -= stoi(s);
            }
        }

        for (string& s : rs)
        {
            // cout << "rs " << s << endl;
            // 对于左侧： x则直接加在lhs里
            if (s.find("x") != s.npos)
            {
                lhs -= GetXCoefficent(s);
            }
            else
            {
                rhs += stoi(s);
            }
        }
        // 考虑三种情况
        if (lhs == 0 && rhs == 0)
        {
            return "Infinite solutions";
        }
        else if (lhs == 0 && rhs != 0)
        {
            return "No solution";
        } 
        else
        {
            // cout << rhs << " " << lhs << endl;
            return "x=" + to_string(rhs/lhs);
        }
    }
};
int main(){
  cout<<"ans is:"<<(new Solution())->solveEquation("x+1=1")<<endl;
  return 0;
}

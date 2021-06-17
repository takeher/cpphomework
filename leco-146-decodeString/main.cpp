#include<iostream>
using namespace std;
class Solution {
public:
    string src;
    size_t ptr;

    int getDigits() {
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr])) {
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    string getString() {
        if (ptr == src.size() || src[ptr] == ']') {
            // String -> EPS
            return "";
        }

        char cur = src[ptr]; int repTime = 1;
        string ret;

        if (isdigit(cur)) {
            // String -> Digits [ String ] String
            // 解析 Digits
            repTime = getDigits();
            // 过滤左括号
            ++ptr;
            // 解析 String
            string str = getString();
            // 过滤右括号
            ++ptr;
            // 构造字符串
            while (repTime--) ret += str;
        } else if (isalpha(cur)) {
            // String -> Char String
            // 解析 Char
            ret = string(1, src[ptr++]);
        }

        return ret + getString();
    }

    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getString();
    }
};
int main(int argc, char *argv[])
{
	string s = "3[a]2[bc]";
	Solution sol;
	cout<<"ans is:"<<sol.decodeString(s)<<endl;
	return 0;
}

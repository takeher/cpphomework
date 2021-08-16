#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        // 去掉字符串开头的空白字符
        while (left <= right && s[left] == ' ') ++left;
        // 去掉字符串末尾的空白字符
        while (left <= right && s[right] == ' ') --right;
        deque<string> d;
        string word;
        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                d.push_front(move(word));
                word = "";
            }
            else if (c != ' ') {
                word += c;
            }
            ++left;
        }
        d.push_front(move(word));

        string ans;
        while (!d.empty()) {
            ans += d.front();
            d.pop_front();
            if (!d.empty()) ans += ' ';
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
	string s = "the sky is blue";
	Solution sol;
	string ans = sol.reverseWords(s);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

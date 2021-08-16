#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
	string max = "", m = "";
	int l = s.size();
	int i = 0;
	if(l == 1){max = s;}
	while (i < l){
		if(i == 0){
			if(s[i] == s[i + 1]){ m = m + s[i] + s[i];}
			else { m = m + s[i];}
			max = max.size()>=m.size()?max:m;
			++i;
		}
		else if(i == l - 1){
			m = "";
			if(s[i] == s[i - 1]){ m = m + s[i] + s[i];}
			else { m = m + s[i];}
			max = max.size()>=m.size()?max:m;
			++i;
		}
		else {
			int j = 1;
			int t = 0;
			while( i + j < l && i - j - t >= 0)	{
				if(j == 1 && s[i] == s[i + 1]){ t = 1;};
				if(s[i + j] != s[i - j - t]){
					if(j == 1){
						m = "";
						m = (s[i]==s[i+1]?(m + s[i] + s[i]):(m + s[i]));
						max = max.size()>=m.size()?max:m;
						++i;
						break;
					}
					m.assign(s,i - j + 1 - t,i + j - 1);
					max = max.size()>=m.size()?max:m;
					++i;
					j = 1;
					t = 0;
					break;
				}
				else if( ((i + j == l - 1)||( (i - j - t) == 0) ) && s[i + j] == s[i - j - t]){
					m.assign(s,i - j - t,i + j + 1);
					max = max.size()>=m.size()?max:m;
					++i;
					j = 1;
					t = 0;
				}
				else {
					++j;

				}
			}
		}
	}
	return max;
    }
};
int main(int argc, char *argv[])
{
	string s = "cbbd";
	Solution sol;
	cout<< "the longest substr is: ";
	string max = sol.longestPalindrome(s);
	cout<< max << endl;
	return 0;
}
/*
 class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

*/
/*

 class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};

 */

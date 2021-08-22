#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 > n2)
            return false;
        int need_cnt = n1;
        unordered_map<char, int> need_char_cnt;
        for (char c : s1)
            need_char_cnt[c] ++;
        //---- 先看s2的前n1个
        for (int i = 0; i < n1; i ++)
        {
            char c = s2[i];
            if (need_char_cnt.find(c) != need_char_cnt.end())
            {
                if (need_char_cnt[c] > 0)
                    need_cnt --;
                need_char_cnt[c] --;
            }
        }

        if (need_cnt == 0)
            return true;
        //---- 维持一个长度为n1的滑动窗口
        for (int r = n1; r < n2; r ++)
        {
            int l = r - n1;
            if (need_char_cnt.find(s2[l]) != need_char_cnt.end())
            {
                if (need_char_cnt[s2[l]] >= 0)
                    need_cnt ++;
                need_char_cnt[s2[l]] ++;
            }
            if (need_char_cnt.find(s2[r]) != need_char_cnt.end())
            {
                if (need_char_cnt[s2[r]] > 0)
                    need_cnt --;
                need_char_cnt[s2[r]] --;
            }

            if (need_cnt == 0)
                return true;
        }

        return false;
    }
};
int main(){
  cout << "ans is:"
       << (new Solution())->checkInclusion("ab", "eidbaooo")<<endl;
  return 0;
}

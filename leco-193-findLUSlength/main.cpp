#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool isSubStr(string &a, string &b){//判断a是否为b的子串
        int i = 0;
        for (auto c: b)
            if (i < a.size() && c == a[i]) i++ ;
        return i == a.size();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),[](string a, string b){//按照长度从大到小排
            return a.size()>b.size();
        });
        for(int i = 0; i < strs.size(); i++){//按照长度从大到小枚举串i 判断i会否是特殊序列
            bool isSub = false;//先假设i不是任何串的子串
            for(int j = 0; j < strs.size()&&strs[i].size() <= strs[j].size(); j++){//判断i是否为j的子串
                if(i!=j&&isSubStr(strs[i],strs[j])){//若i是j的子串 则i不是特殊序列 跳出即可
                    isSub = true;
                    break;
                }
            }
            if(!isSub) return strs[i].size();//i不是任何串的子串 则为特殊序列 直接返回即可
        }
        return -1;
    }
};
int main(int argc, char *argv[])
{
	vector<string> strs{"aba", "cdc", "eae"};
	Solution sol;
	cout<<"ans is:"<<sol.findLUSlength(strs)<<endl;
	return 0;
}

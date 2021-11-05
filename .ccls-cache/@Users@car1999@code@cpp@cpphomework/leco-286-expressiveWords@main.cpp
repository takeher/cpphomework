#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            string &word=words[i];
            int cur1=0,cur2=0;
            bool flag=false;
            while(cur1<s.size()){
                int j=cur1;
                cur1++;
                while(cur1<s.size()&&s[cur1]==s[j])cur1++;
                int len1=cur1-j;
                if(word[cur2]!=s[j]){
                    flag=true;
                    break;
                }
                int k=cur2;
                cur2++;
                while(cur2<word.size()&&word[cur2]==word[k])cur2++;
                int len2=cur2-k;
                if(len1<=2&&len1!=len2){
                    flag=true;
                    break;
                }
                else if(len1>=3&&len2>len1){
                    flag=true;
                    break;
                }
            }
            if(cur2!=word.size())flag=true;
            if(flag==false)ans++;
        }
        return ans;
    }
};
int main(){
  auto words = vector<string>{"hello", "hi", "helo"};
  cout<<"ans is:"<<(new Solution())->expressiveWords("heeellooo", words)<<endl;
  return 0;
}

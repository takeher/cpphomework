#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<char,int> m7{{'0',0},{'1',1},{'2',2},{'5',3},{'6',4},{'8',5},{'9',6}};//对应为7进制
    map<char,int> m3{{'0',0},{'1',1},{'8',2}};////对应为3进制

    string figure7="9865210";
    string figure3="810";

    int rotatedDigits(int N) {
        return GetMaxAndToTen(N,figure7,m7)-GetMaxAndToTen(N,figure3,m3);
    }

    int GetMaxAndToTen(int n,string figure,map<char,int> &m){
        //1.范围n(包括)内，找到figure能组合的最大数字 (两个for,但是是个单循环)
        string str=to_string(n);
        for(int i=0;i<str.size();i++){
            char e=str[i];
            auto iter=find_if(figure.begin(),figure.end(),[=](char c){return c<=e;});//ASCII
            if(*iter!=e){
                str[i++]=*iter;
                for(;i<str.size();i++){
                    str[i]=figure[0];
                }
                break;
            }
        }
        //2.字符映射-进制转换
        int r=0;
        int k=figure.size();//k进制转10进制
        for(auto c:str){
            r=r*k+m[c];
        }
        return r;
    }
};
int main(){
  cout<<"ans is:"<<(new Solution())->rotatedDigits(10)<<endl;
  return 0;
}

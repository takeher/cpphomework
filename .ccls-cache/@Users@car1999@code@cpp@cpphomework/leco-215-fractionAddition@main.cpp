#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string fractionAddition(string expression) {
        int n=count(expression.begin(),expression.end(),'/');
        if(expression[0]!='-'&&expression[0]!='+')expression='+'+expression;
        int addA=0,addB=1;
        int offset=0;
        for(int i=0;i<n;i++){
            char sign;
            int a,b;
            sscanf(expression.c_str()+offset,"%c%d/%d",&sign,&a,&b);
            offset+=(to_string(a)+to_string(b)).size()+2;
            if(sign=='-')a*=-1;
            int newA=addA*b+a*addB;
            int newB=addB*b;
            int gcdNum=abs(gcd(newA,newB));
            addA=newA/gcdNum;
            addB=newB/gcdNum;
        }
        return to_string(addA)+'/'+to_string(addB);
    }
    int gcd(int a,int b){
        //cout<<a<<' '<<b<<endl;
        while(a!=0){
            int tmpA=a;
            a=b%a;
            b=tmpA;
        }
        //cout<<b<<endl;
        return b;
    }
};
int main(){
  cout << "ans is:"<< (new Solution())->fractionAddition("-1/2+1/2+1/3")<<endl;
  return 0;
}

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
	int num = 0;
	int flag = 1, start = 0, end = 0;
	int l = s.size();
	if(s.empty()){return 0;}
	for(int i = 0;i < l;++i){
		if( (s[i] != ' ') ){
			if( s[i] == '-'){ flag = -1; start = i + 1;break;}
			else if( s[i] == '+'){ start = i + 1;break;}
			else if( (s[i] <= '9') && (s[i] > '0') ){ start = i;break;}
			else if( s[i] == '0'){if(i != (l - 1) ){if( ( s[i + 1] >= '9') || ( s[i + 1] < '0') ){ return 0;}else{start = i + 1;break;} }else{return 0;} }
			else{return 0;}
		}
	}
	for (int i = start; i < l; ++i) {
		if( (s[i] > '9')||(s[i] < '0') ){ end = i - 1;break;}
		else if( i == (l - 1)){end = i;break;}
	}
	if(end < start){return 0;}
	for(int i = start;i <= end;++i)
	{
		if(s[i] != '0'){start = i;break;}
		else if( (i == end) && (s[i] == '0') ){return 0;}
	}
	if( ( (end - start + 1) > 10)){  return flag==-1?-2147483648:2147483647;}
	else if( (end - start + 1) == 10){
		if(s[start] > '2'){ return flag==-1?-2147483648:2147483647;}
		else if( (s[start] >= '2')&& ( stoi(s.substr(start + 1, 9)) > 147483647 ) ){ return flag==-1?-2147483648:2147483647; }
	}
	num = stoi(s.substr(start, end - start + 1));
	num = flag*num;
	return num;
    }
};
int main(int argc, char *argv[])
{
	//string s = "-42";
//	string s = "words and 987";
	string s = " 1175109307q7";
	Solution sol;
	int num = sol.myAtoi(s);
	cout<<"num is:"<< num <<endl;
	return 0;
}
